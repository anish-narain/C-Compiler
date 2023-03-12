#include "ast_hpp/declarations/ast_ParamDeclaration.hpp"

//Constructor 
Param_Declarator::Param_Declarator(BasePtr declaration_specifier, BasePtr declarator)
{
    branchList.insert(branchList.end(), {declaration_specifier, declarator});
}
//Destructor
Param_Declarator::~Param_Declarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Param_Declarator::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void Param_Declarator::RISCOutput(std::ostream &dst, int destReg) const
{}