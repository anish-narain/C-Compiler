#include "ast_hpp/statements/ast_IfElse.hpp"

//Constuctor
If_Else::If_Else(BasePtr expression, BasePtr if_statement, BasePtr else_statement)
{
    branchList.insert(branchList.end(), {expression, if_statement, else_statement});
}

//Destructor
If_Else::~If_Else()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void If_Else::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Condition [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "] endCondition" << std::endl;
  dst << indent << "If Scope [" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "] endIfScope" << std::endl;
  dst << indent << "Else Scope [" << std::endl;
  branchList[2]->print(dst, indent+"  ");
  dst << indent << "] endElseScope" << std::endl;
}



void If_Else::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context, destReg);
  branchList[1]->RISCOutput(dst, context, destReg);
  
}

int If_Else::getSize() const{
  return branchList[0]->getSize();
}

