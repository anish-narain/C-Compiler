#include "ast_hpp/operators/ast_Add.hpp"

//Constructor 
Add::Add(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Add::~Add()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Add::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Add Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Add::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
 
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    branchList[0]->RISCOutput(dst, context, left_reg);
    branchList[1]->RISCOutput(dst, context, right_reg);

    std::string right = context.reg(right_reg);
    std::string left = context.reg(left_reg);

    dst << "add " << context.reg(destReg) << ", " << context.reg(left_reg) << ", " << context.reg(right_reg) << std::endl;
 
}



int Add::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}