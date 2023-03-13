#include "ast_hpp/operators/ast_ShiftLeft.hpp"

//Constructor 
ShiftLeft::ShiftLeft(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
ShiftLeft::~ShiftLeft()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void ShiftLeft::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Shift Left Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void ShiftLeft::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int ShiftLeft::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}