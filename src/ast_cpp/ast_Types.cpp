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
  else if (type == "double"){
    dst << indent << "TYPE: " << "double" << indent << std::endl;
  }
  else if (type == "float"){
    dst << indent << "TYPE: " << "float" << indent << std::endl;
  }
}

void Types::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
}

int Types::getSize() const
{
  if (type == "int"){
    return 4;
  }
  if (type == "double"){
    return 4;
  }
  if (type == "float"){
    return 4;
  }
}

