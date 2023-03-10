#include "ast_hpp/operators/ast_BitwiseAnd.hpp"

//Constructor 
BitwiseAnd::BitwiseAnd(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
BitwiseAnd::~BitwiseAnd()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void BitwiseAnd::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Bitwise And Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void BitwiseAnd::RISCOutput(std::ostream &dst, int destReg) const
{}