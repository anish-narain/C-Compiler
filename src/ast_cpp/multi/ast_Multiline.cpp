#include "ast_hpp/multi/ast_Multiline.hpp"

//Constructor 
Multiline::Multiline(BasePtr declaration_list, BasePtr statement_list)
{
    branchList.insert(branchList.end(), {declaration_list, statement_list});
}
//Destructor
Multiline::~Multiline()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Multiline::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Compound Statements [" << std::endl;
    branchList[0]->print(dst, indent+"  ");
    branchList[1]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
}

void Multiline::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int Multiline::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void Multiline::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

int Multiline::isFunctionCall() const{
  branchList[0]->isFunctionCall();
  branchList[1]->isFunctionCall();
}