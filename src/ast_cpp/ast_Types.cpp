#include "ast_hpp/ast_Types.hpp"

Types::Types(std::string dataType)
    :type(dataType) 
{}
//Destructor
Types::~Types()
{}

//Print
void Types::print(std::ostream &dst, std::string indent) const
{
  if (type == "int"){
    dst << indent << "TYPE: " << "int" << indent << std::endl;
  }
}

void Types::RISCOutput(std::ostream &dst, int destReg) const
{}