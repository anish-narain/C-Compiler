#include "ast_hpp/ast_BitwiseOr.hpp"

//Constructor 
BitwiseOr::BitwiseOr(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
BitwiseOr::~BitwiseOr()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void BitwiseOr::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "BitwiseOr Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void BitwiseOr::RISCOutput(std::ostream &dst, int destReg) const
{}