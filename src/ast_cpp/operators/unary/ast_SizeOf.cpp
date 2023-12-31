#include "ast_hpp/operators/unary/ast_SizeOf.hpp"

//Constructor 
SizeOf::SizeOf(BasePtr value)
{
    branchList.insert(branchList.end(), {value});
}
//Destructor
SizeOf::~SizeOf()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void SizeOf::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "SizeOf [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void SizeOf::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int size = branchList[0]->getSize();

    if (size==0){ //reached an Id
      std::string var_name = branchList[0]->Returnid();
      std::string type = context.returnVarType(var_name);
      if(type == "int"){
        size = 4;
      }
      else if(type == "char"){
        size = 1;
      }
    }

    branchList[0]->RISCOutput(dst, context, destReg);
    dst << "li " << context.reg(destReg) << "," << size << std::endl;
}

/*
void SizeOf::createParameterMap(context &context) const{
  branchList[0]->createParameterMap(context);
}
*/

int SizeOf::getSize() const{
  return branchList[0]->getSize();
}