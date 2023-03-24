#include "ast_hpp/operators/pointer/ast_Pointer.hpp"

//Constructor 
Pointer::Pointer()
{}
//Destructor
Pointer::~Pointer()
{}

//Print
void Pointer::print(std::ostream &dst, std::string indent) const
{
    dst << "Pointer: ";
}

void Pointer::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int Pointer::getSize() const{
  return 0;
}

void Pointer::isFunctionCall(context &context) const{}

void Pointer::createVariableMap(context &context) const{}

void  Pointer::isPointer(context &context) const{}