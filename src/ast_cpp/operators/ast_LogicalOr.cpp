#include "ast_hpp/operators/ast_LogicalOr.hpp"

//Constructor 
LogicalOr::LogicalOr(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
LogicalOr::~LogicalOr()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void LogicalOr::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "LogicalOr Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void LogicalOr::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    branchList[0]->RISCOutput(dst, context, left_reg);
    branchList[1]->RISCOutput(dst, context, right_reg);

    std::string right = context.reg(right_reg);
    std::string left = context.reg(left_reg);

    dst << "or " << context.reg(destReg) << ", " << context.reg(left_reg) << ", " << context.reg(right_reg) << std::endl;
}

int LogicalOr::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}