#include "ast_hpp/operators/ast_Multiply.hpp"

//Constructor 
Multiply::Multiply(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Multiply::~Multiply()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Multiply::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Multiply Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Multiply::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int Multiply::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}