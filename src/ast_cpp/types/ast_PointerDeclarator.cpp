#include "ast_hpp/types/ast_PointerDeclarator.hpp"

//Constructor 
PointerDeclarator::PointerDeclarator(BasePtr direct_declarator)
{
    branchList.insert(branchList.end(), {direct_declarator});
}
//Destructor
PointerDeclarator::~PointerDeclarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void PointerDeclarator::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Pointer Declarator [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void PointerDeclarator::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    branchList[0]->RISCOutput(dst, context, destReg);
}

int PointerDeclarator::getSize() const{
  return branchList[0]->getSize();
}

void PointerDeclarator::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}