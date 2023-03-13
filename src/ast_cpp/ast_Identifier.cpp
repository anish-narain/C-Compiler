#include "ast_hpp/ast_Identifier.hpp"

//Constructor 
Identifier::Identifier(std::string IDENTIFIER)
  :id(IDENTIFIER) 
{}
//Destructor
Identifier::~Identifier()
{}

//Print
void Identifier::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "IDENTIFIER " << id << std::endl;
}

//Codegen
void Identifier::RISCOutput(std::ostream &dst, int destReg) const
{
  dst << ".globl "<< id << std::endl; // will need to add parameters 
  dst << id << ":" << std::endl; // will need to add parameters 
}

int Identifier::getSize() const{}