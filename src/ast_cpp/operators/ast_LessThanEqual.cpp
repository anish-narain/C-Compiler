#include "ast_hpp/operators/ast_LessThanEqual.hpp"

//Constructor 
LessThanEqual::LessThanEqual(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
LessThanEqual::~LessThanEqual()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void LessThanEqual::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "LessThanEqual Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void LessThanEqual::RISCOutput(std::ostream &dst, int destReg) const
{}