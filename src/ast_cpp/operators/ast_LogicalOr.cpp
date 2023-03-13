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
{}

int LogicalOr::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}