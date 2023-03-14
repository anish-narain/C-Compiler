#include "ast_hpp/declarations/ast_VariableAssign.hpp"

//Constructor 
VariableAssign::VariableAssign(BasePtr declaration, BasePtr initializer)
{
    branchList.insert(branchList.end(), {declaration, initializer});
}
//Destructor
VariableAssign::~VariableAssign()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void VariableAssign::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Variable Assign [" << std::endl;
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
    dst << indent << "]" << std::endl;
}

void VariableAssign::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int VariableAssign::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}