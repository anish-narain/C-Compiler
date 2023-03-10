#include "ast_hpp/ast_GreaterThanEqual.hpp"

//Constructor 
GreaterThanEqual::GreaterThanEqual(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
GreaterThanEqual::~GreaterThanEqual()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void GreaterThanEqual::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "GreaterThanEqual Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Types::RISCOutput(std::ostream &dst, int destReg) const
{}