#include "ast_hpp/operators/ast_LessThan.hpp"

//Constructor 
LessThan::LessThan(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
LessThan::~LessThan()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void LessThan::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "LessThan Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void LessThan::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int LessThan::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}