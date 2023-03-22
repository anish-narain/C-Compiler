#include "ast_hpp/ast_Integer.hpp"

// Constructor
Int::Int(int val)
  : int_value(val)
{}

Int::Int() // Default initializer
  : Int(0)
{}

//Destructor
Int::~Int()
{}

// Visualising
void Int::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Integer : " << int_value << std::endl;
}

void Int::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  dst << "li "<< context.reg(destReg) << "," << int_value << std::endl;
}

std::string Int::Returnid() const{ //hacky solution
  return "int";
}

int Int::getSize() const{
  return 0;
}

int Int::isFunctionCall() const{
  return 0;
}

