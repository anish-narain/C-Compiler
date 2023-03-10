#include "ast_hpp/operators/ast_Equal.hpp"

//Constructor 
Equal::Equal(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Equal::~Equal()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Equal::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Equal Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Equal::RISCOutput(std::ostream &dst, int destReg) const
{}