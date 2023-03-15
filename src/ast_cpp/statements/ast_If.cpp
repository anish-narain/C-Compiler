#include "ast_hpp/statements/ast_If.hpp"

//Constuctor
If::If(BasePtr expression, BasePtr if_statement)
{
    branchList.insert(branchList.end(), {expression, if_statement});
}

//Destructor
If::~If()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void If::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Condition [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "] endCondition" << std::endl;
  dst << indent << "If Scope [" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "] endIfScope" << std::endl;
}



void If::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context, destReg);
  branchList[1]->RISCOutput(dst, context, destReg);
}

int If::getSize() const{
  return branchList[0]->getSize();
}
