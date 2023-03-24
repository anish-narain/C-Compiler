#include "ast_hpp/statements/ast_While.hpp"

//Constuctor
While::While(BasePtr expression, BasePtr statement)
{
    branchList.insert(branchList.end(), {expression, statement});
}

//Destructor
While::~While()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void While::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "While condition [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "] endCondition" << std::endl;
  dst << indent << "Do scope [" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "] endDoScope" << std::endl;
}



void While::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int condition_reg = context.allocateRegister();
    std::string branch1 = context.allocateJumpBranch();
    std::string branch2 = context.allocateJumpBranch();
    std::string condition = context.reg(condition_reg);
    

    dst << "j ." << branch1 << std::endl;
    dst << "." << branch2 << ":" << std::endl;
    branchList[1]->RISCOutput(dst, context, destReg);

    dst << "." << branch1 << ":" << std::endl;
    branchList[0]->RISCOutput(dst, context, condition_reg);
    dst << "bne " << condition << ", zero , ." << branch2 << std::endl;

    
}

int While::getSize() const{
  return branchList[0]->getSize();
}

void While::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

void While::isFunctionCall(context &context) const{
  branchList[0]->isFunctionCall(context); 
  branchList[1]->isFunctionCall(context);
}

void  While::isPointer(context &context) const{
  branchList[0]->isPointer(context);
  branchList[1]->isPointer(context);
}