#include "ast_hpp/statements/ast_For.hpp"

//Constuctor
For::For(BasePtr initialize, BasePtr condition, BasePtr increment, BasePtr statement)
{
    branchList.insert(branchList.end(), {initialize, condition, increment, statement});
}

//Destructor
For::~For()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void For::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "For initilisation [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent+"  " << "Condition: " << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent+"  " << "Increment: " << std::endl;
  branchList[2]->print(dst, indent+"  ");
  dst << indent << "] endInitialisation" << std::endl;
  dst << indent << "Do scope [" << std::endl;
  branchList[3]->print(dst, indent+"  ");
  dst << indent << "]endDoScope" << std::endl;
}

void For::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  int condition_reg = context.allocateRegister();
  std::string branch1 = context.allocateJumpBranch();
  std::string branch2 = context.allocateJumpBranch();
  std::string condition = context.reg(condition_reg);
  
  branchList[0]->RISCOutput(dst, context, destReg);
  
  dst << "j ." << branch1 << std::endl;
  dst << "." << branch2 << ":" << std::endl;
  
  branchList[3]->RISCOutput(dst, context, destReg);
  branchList[2]->RISCOutput(dst, context, destReg);

  dst << "." << branch1 << ":" << std::endl;
  branchList[1]->RISCOutput(dst, context, condition_reg);
  dst << "bne " << condition << ", zero , ." << branch2 << std::endl;
}

int For::getSize() const{
  return branchList[0]->getSize();
}

void For::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

int For::isFunctionCall() const{
  return branchList[0]->isFunctionCall() + branchList[1]->isFunctionCall();
 
}
