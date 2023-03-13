#include "ast_hpp/operators/ast_BitwiseXor.hpp"

//Constructor 
BitwiseXor::BitwiseXor(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
BitwiseXor::~BitwiseXor()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void BitwiseXor::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Bitwise Xor Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void BitwiseXor::RISCOutput(std::ostream &dst, int destReg) const
{}

int BitwiseXor::getSize() const{}