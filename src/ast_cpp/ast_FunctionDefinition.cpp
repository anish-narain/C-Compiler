#include "ast_hpp/ast_FunctionDefinition.hpp"

//Constructor 
Function_Definition::Function_Definition(BasePtr declaration_specifier, BasePtr declarator, BasePtr compound_statement)
{
    branchList.insert(branchList.end(), {declaration_specifier, declarator, compound_statement});
}
//Destructor
Function_Definition::~Function_Definition()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Function_Definition::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Function Definition [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  branchList[1]->print(dst, indent+"  ");
  branchList[2]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}