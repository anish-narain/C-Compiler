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
{}

int LogicalAnd::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}