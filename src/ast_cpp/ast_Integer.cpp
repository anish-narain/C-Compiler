#include "ast_hpp/ast_Integer.hpp"

// Constructor
Int::Int(int val)
  : int_value(val)
{}

//Destructor
Int::~Int()
{
}

// Visualising
void Int::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Integer = " << int_value << std::endl;
}