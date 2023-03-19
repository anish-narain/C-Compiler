#include "ast_hpp/operators/unary/ast_Unary.hpp"

//Constructor 
Unary::Unary(BasePtr unary_operator, BasePtr cast_expression)
{
    branchList.insert(branchList.end(), {unary_operator, cast_expression});
}
//Destructor
Unary::~Unary()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Unary::print(std::ostream &dst, std::string indent) const
{
  branchList[0]->print(dst, indent+"  ");
  branchList[1]->print(dst, indent+"  ");
}

void Unary::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    branchList[0]->RISCOutput(dst, context, destReg);
    branchList[1]->RISCOutput(dst, context, destReg);
}

int Unary::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}