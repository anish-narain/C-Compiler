#include "ast_hpp/ast_FunctionNameDeclarator.hpp"

//Constructor 
Function_Name_Declarator::Function_Name_Declarator(std::string IDENTIFIER)
  :id(IDENTIFIER) 
{
}
//Destructor
Function_Name_Declarator::~Function_Name_Declarator()
{
}

//Print
void Function_Name_Declarator::print(std::ostream &dst, std::string indent) const
{
  
    dst << id;
  
}

void Function_Name_Declarator::RISCOutput(std::ostream &dst, int destReg) const
{
  dst << ".globl "<< id << std::endl; // will need to add parameters 
  dst << id << ":" << std::endl; // will need to add parameters 
}

