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
  else if (type == "unsigned"){
    dst << indent << "TYPE: " << "unsigned" << indent << std::endl;
  }
}

void Types::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
}

int Types::getSize() const
{
  
  if (type == "char"){
    return 1;
  }
  else if (type == "double"){
    return 8;
  }
  else if (type == "float"){
    return 8;
  }
  else{
    return 4;
  }
}

std::string Types::getType() const
{
  return type;
}

int Types::isFunctionCall() const{
  return 0;
}

