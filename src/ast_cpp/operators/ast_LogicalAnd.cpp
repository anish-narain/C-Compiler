#include "ast_hpp/operators/ast_LogicalAnd.hpp"

//Constructor 
LogicalAnd::LogicalAnd(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
LogicalAnd::~LogicalAnd()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void LogicalAnd::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "LogicalAnd Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void LogicalAnd::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    branchList[0]->RISCOutput(dst, context, left_reg);
    branchList[1]->RISCOutput(dst, context, right_reg);

    std::string right = context.reg(right_reg);
    std::string left = context.reg(left_reg);

    std::string leftNode = branchList[0]->Returnid();
    int stackOfLHS = context.get_var_location(leftNode);
    std::string rightNode = branchList[1]->Returnid();
    int stackOfRHS = context.get_var_location(rightNode);

    std::string branch1 = context.allocateJumpBranch();
    std::string branch2 = context.allocateJumpBranch();

    dst << "lw " << context.reg(destReg) << ", " << stackOfLHS << "(s0)" << std::endl;
    dst << "beq " << context.reg(destReg) << ", " << "zero, ." << branch1 << std::endl;
    dst << "lw " << context.reg(destReg) << ", " << stackOfRHS << "(s0)" << std::endl;
    dst << "beq " << context.reg(destReg) << ", " << "zero, ." << branch2 << std::endl;
    dst << "li " << context.reg(destReg) << ", 1" << std::endl;
    dst << "j ." << branch2 << std::endl;
    dst << "." << branch1 << ":" << std::endl;
    dst << "li " << context.reg(destReg) << ", 0" << std::endl;
    dst << "." << branch2 << ":" << std::endl;

}

int LogicalAnd::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void LogicalAnd::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}