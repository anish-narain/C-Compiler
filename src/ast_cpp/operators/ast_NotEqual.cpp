#include "ast_hpp/operators/ast_NotEqual.hpp"

//Constructor 
NotEqual::NotEqual(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
NotEqual::~NotEqual()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void NotEqual::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "NotEqual Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void NotEqual::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    branchList[0]->RISCOutput(dst, context, left_reg);
    branchList[1]->RISCOutput(dst, context, right_reg);

    std::string right = context.reg(right_reg);
    std::string left = context.reg(left_reg);

    dst << "sub " << context.reg(right_reg) << ", " << context.reg(left_reg) << ", " << context.reg(right_reg) << std::endl;
    dst << "snez " << context.reg(right_reg) << ", " << context.reg(right_reg) << std::endl;
    dst << "andi " << context.reg(destReg) << ", " << context.reg(right_reg) << ", " << "0xff" << std::endl;
}

int NotEqual::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}