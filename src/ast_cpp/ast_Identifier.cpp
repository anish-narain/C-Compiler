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
void Identifier::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  dst << "lw" << context.reg(destReg) <<  ", " << context.get_var_location(id) << "(s0)" <<std::endl;
}

std::string Identifier::Returnid() const{
  return id;
}

int Identifier::getSize() const{
  return 0;
}



