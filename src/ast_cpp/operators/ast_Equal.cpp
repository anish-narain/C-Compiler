#include "ast_hpp/operators/ast_Equal.hpp"

//Constructor 
Equal::Equal(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Equal::~Equal()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Equal::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Equal Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Equal::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    branchList[0]->RISCOutput(dst, context, left_reg);
    branchList[1]->RISCOutput(dst, context, right_reg);

    std::string right = context.reg(right_reg);
    std::string left = context.reg(left_reg);

    dst << "sub " << context.reg(right_reg) << ", " << context.reg(left_reg) << ", " << context.reg(right_reg) << std::endl;
    dst << "seqz " << context.reg(right_reg) << ", " << context.reg(right_reg) << std::endl;
    dst << "andi " << context.reg(destReg) << ", " << context.reg(right_reg) << ", " << "0xff" << std::endl;
}

int Equal::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void Equal::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}