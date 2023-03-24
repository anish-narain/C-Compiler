#include "ast_hpp/operators/unary/ast_UnaryPostOp.hpp"

//Constructor 
UnaryPostOp::UnaryPostOp(BasePtr postfix_expression, std::string operation)
    :op(operation)
{
    branchList.insert(branchList.end(), {postfix_expression});
}
//Destructor
UnaryPostOp::~UnaryPostOp()
{
    for (auto branch : branchList) {
        delete branch;
    }
}

//Print
void UnaryPostOp::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent+"  ");
    if (op == "--"){
        dst << "DECREMENT";
    }
    else if(op == "++"){
        dst << "INCREMENT";
    }
}

void UnaryPostOp::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    branchList[0]->RISCOutput(dst, context, destReg);
    std::string var_name = branchList[0]->Returnid();
    int variableallocate = context.get_var_location(var_name);
    dst << "addi " << context.reg(destReg) << ", " << context.reg(destReg) << ", -1" << std::endl;
    dst << "sw " << context.reg(destReg) << ", " << variableallocate << "(s0)" <<std::endl;
}

int UnaryPostOp::getSize() const{
  return branchList[0]->getSize();
}

void UnaryPostOp::isFunctionCall(context &context) const{
}

void UnaryPostOp::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
}

std::string UnaryPostOp::Returnid() const{
}

void  UnaryPostOp::isPointer(context &context) const{}