#include "ast_hpp/calls/ast_ArgDeclaration.hpp"

//Constructor 
Arg_Declarator::Arg_Declarator(BasePtr assignment_expression)
{
    branchList.insert(branchList.end(), {assignment_expression});
}
//Destructor
Arg_Declarator::~Arg_Declarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Arg_Declarator::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
}

void Arg_Declarator::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context , 10);
}

int Arg_Declarator::getSize() const
{
  return branchList[0]->getSize();
}

void Arg_Declarator::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
}

int Arg_Declarator::GetArgLocation() const{
  return 10;
}