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
  dst << indent << "If Scope [" << std::endl;
  dst << indent << "Condition [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "] endCondition" << std::endl;
  dst << indent << "If Statement  [" << std::endl;
  branchList[1]->print(dst, indent+"  ");
   dst << indent << "] end If Statement" << std::endl;
  dst << indent << "] endIfScope" << std::endl;
}



void If::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int condition_reg = context.allocateRegister();
    std::string end = context.allocateJumpBranch();
    std::string condition = context.reg(condition_reg);

    branchList[0]->RISCOutput(dst, context, condition_reg);
    dst << "beq " << condition << ", zero , ." << end << std::endl;
    branchList[1]->RISCOutput(dst, context, destReg);
    dst << "." << end << ":" << std::endl;
  
}

int If::getSize() const{
  return branchList[0]->getSize();
}

void If::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

int If::isFunctionCall() const{
  return branchList[0]->isFunctionCall() + branchList[1]->isFunctionCall();
 
}
