#include "ast_hpp/declarations/ast_ParamListDeclaration.hpp"

//Constructor 
Param_List_Declarator::Param_List_Declarator(BasePtr parameter_list, BasePtr parameter_declaration)
{
    branchList.insert(branchList.end(), {parameter_list, parameter_declaration});
}
//Destructor
Param_List_Declarator::~Param_List_Declarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Param_List_Declarator::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void Param_List_Declarator::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int Param_List_Declarator::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void Param_List_Declarator::createParameterMap(context &context) const{
  branchList[0]->createParameterMap(context);
  branchList[1]->createParameterMap(context);
}

void Param_List_Declarator::isPointer(context &context) const{
  branchList[0]->isPointer(context);
  branchList[1]->isPointer(context);
}