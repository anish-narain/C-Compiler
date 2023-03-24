#include "ast_hpp/declarations/ast_FunctionDeclaratorWithParam.hpp"

//Constructor 
Function_Declarator_With_Param::Function_Declarator_With_Param(BasePtr direct_declarator, BasePtr parameter_type_list)
{
    branchList.insert(branchList.end(), {direct_declarator, parameter_type_list});
}
//Destructor
Function_Declarator_With_Param::~Function_Declarator_With_Param()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Function_Declarator_With_Param::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent+"  ");
    branchList[1]->print(dst, indent+"  ");
}

void Function_Declarator_With_Param::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int Function_Declarator_With_Param::getSize() const{
   return branchList[0]->getSize() + branchList[1]->getSize();
}

BasePtr Function_Declarator_With_Param::returnBranch(int index) const{
  return branchList[index];
}

std::string Function_Declarator_With_Param::Returnid() const{
  return branchList[0]->Returnid();
}

void Function_Declarator_With_Param::createParameterMap(context &context) const{
  branchList[1]->createParameterMap(context);
}

void Function_Declarator_With_Param::isPointer(context &context) const{
  branchList[0]->isPointer(context);
  branchList[1]->isPointer(context);
}

