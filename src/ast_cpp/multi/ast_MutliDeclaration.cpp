#include "ast_hpp/multi/ast_MultiDeclaration.hpp"

//Constructor 
MultiDeclaration::MultiDeclaration(BasePtr declaration_list, BasePtr declaration)
{
    branchList.insert(branchList.end(), {declaration_list, declaration});
}
//Destructor
MultiDeclaration::~MultiDeclaration()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void MultiDeclaration::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void MultiDeclaration::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int MultiDeclaration::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void MultiDeclaration::createVariableMap(context &context) const{
    branchList[0]->createVariableMap(context);
    branchList[1]->createVariableMap(context);
}

int MultiDeclaration::isFunctionCall() const{
  return branchList[0]->isFunctionCall() + branchList[1]->isFunctionCall();
  
}