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
{}

int NotEqual::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}