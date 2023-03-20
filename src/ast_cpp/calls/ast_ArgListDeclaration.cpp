#include "ast_hpp/calls/ast_ArgListDeclaration.hpp"

//Constructor 
Arg_List_Declarator::Arg_List_Declarator(BasePtr argument_expression_list, BasePtr assignment_expression)
{
    branchList.insert(branchList.end(), {argument_expression_list, assignment_expression});
}
//Destructor
Arg_List_Declarator::~Arg_List_Declarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Arg_List_Declarator::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void Arg_List_Declarator::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int Arg_List_Declarator::getSize() const
{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void Arg_List_Declarator::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}