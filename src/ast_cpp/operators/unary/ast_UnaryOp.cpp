#include "ast_hpp/operators/unary/ast_UnaryOp.hpp"

//Constructor 
UnaryOp::UnaryOp(std::string operation)
    :op(operation)
{}
//Destructor
UnaryOp::~UnaryOp()
{}

//Print
void UnaryOp::print(std::ostream &dst, std::string indent) const
{
    if (op == "-"){
        dst << "MINUS SIGN";
    }
}

void UnaryOp::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int UnaryOp::getSize() const{
  return 0;
}