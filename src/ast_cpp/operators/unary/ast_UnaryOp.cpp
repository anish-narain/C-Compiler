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
    else if (op == "&"){
        dst << "&";
    }
    else if (op == "*"){
        dst << "*";
    }
}

void UnaryOp::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    if (op == "-"){
        dst << "neg " << context.reg(destReg) << "," << context.reg(destReg) << std::endl;
    }
    if (op == "*"){
        dst << "lw " << context.reg(destReg) << ", 0("  << context.reg(destReg) << ")" << std::endl;
    }
}

int UnaryOp::getSize() const{
  return 0;
}

void UnaryOp::isFunctionCall(context &context) const{
     std::cerr << "UnaryOpFunctionCallReached" << std::endl;
}

void UnaryOp::createVariableMap(context &context) const{}

void  UnaryOp::isPointer(context &context) const{}