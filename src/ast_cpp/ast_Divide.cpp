#include "ast_hpp/ast_Divide.hpp"

//Constructor 
Divide::Divide(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Divide::~Divide()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Divide::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Divide Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Divide::RISCOutput(std::ostream &dst, int destReg) const
{}