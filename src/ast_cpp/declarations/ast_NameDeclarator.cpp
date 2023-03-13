#include "ast_hpp/declarations/ast_NameDeclarator.hpp"

//Constructor 
Name_Declarator::Name_Declarator(std::string IDENTIFIER)
  :id(IDENTIFIER) 
{}
//Destructor
Name_Declarator::~Name_Declarator()
{
}

//Print
void Name_Declarator::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "IDENTIFIER " << id << std::endl;
}

void Name_Declarator::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  dst << ".globl "<< id << std::endl; // will need to add parameters 
  dst << id << ":" << std::endl; // will need to add parameters 
}

int Name_Declarator::getSize() const{
  return 0;
}
