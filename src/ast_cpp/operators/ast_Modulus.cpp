#include "ast_hpp/operators/ast_Modulus.hpp"

//Constructor 
Modulus::Modulus(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Modulus::~Modulus()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Modulus::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Modulus Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Modulus::RISCOutput(std::ostream &dst, int destReg) const
{}

int Modulus::getSize() const{}