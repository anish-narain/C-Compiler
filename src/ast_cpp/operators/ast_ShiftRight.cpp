#include "ast_hpp/operators/ast_ShiftRight.hpp"

//Constructor 
ShiftRight::ShiftRight(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
ShiftRight::~ShiftRight()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void ShiftRight::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Shift Right Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void ShiftRight::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int ShiftRight::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}