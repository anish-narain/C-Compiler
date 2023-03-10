#include "ast_hpp/operators/ast_Subtract.hpp"

//Constructor 
Subtract::Subtract(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Subtract::~Subtract()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Subtract::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Subtract Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Subtract::RISCOutput(std::ostream &dst, int destReg) const
{}