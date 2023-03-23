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
}

int UnaryPostOp::getSize() const{
  return branchList[0]->getSize();
}

int UnaryPostOp::isFunctionCall() const{
    return 0;
}

void UnaryPostOp::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
}