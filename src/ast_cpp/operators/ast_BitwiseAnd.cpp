#include "ast_hpp/operators/ast_BitwiseAnd.hpp"

//Constructor 
BitwiseAnd::BitwiseAnd(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
BitwiseAnd::~BitwiseAnd()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void BitwiseAnd::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Bitwise And Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void BitwiseAnd::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    branchList[0]->RISCOutput(dst, context, left_reg);
    branchList[1]->RISCOutput(dst, context, right_reg);

    std::string right = context.reg(right_reg);
    std::string left = context.reg(left_reg);

    dst << "and " << context.reg(destReg) << ", " << context.reg(left_reg) << ", " << context.reg(right_reg) << std::endl;
}

int BitwiseAnd::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}