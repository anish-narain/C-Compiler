#include "ast_hpp/operators/ast_ValueAssign.hpp"

//Constructor 
ValueAssign::ValueAssign(BasePtr unary_expression, BasePtr assignment_expression)
{
    branchList.insert(branchList.end(), {unary_expression, assignment_expression});
}
//Destructor
ValueAssign::~ValueAssign()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void ValueAssign::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Binary Assignment" << "[" << std::endl;
  dst << indent << "LHS" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "RHS" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void ValueAssign::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    branchList[1]->RISCOutput(dst, context, destReg);
    std::string id = branchList[0]->Returnid();
    int addrOfLHS = context.implement_var_binding(id);
     
    dst << "sw " << context.reg(destReg) <<  ", " << addrOfLHS << "(s0)" <<std::endl;
}

int ValueAssign::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}