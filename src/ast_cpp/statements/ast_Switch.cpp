#include "ast_hpp/statements/ast_Switch.hpp"

//Constuctor
Switch::Switch(BasePtr expression, BasePtr statement)
{
    branchList.insert(branchList.end(), {expression, statement});
}

//Destructor
Switch::~Switch()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Switch::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Condition [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "] endCondition" << std::endl;
  dst << indent << "Case 1 [" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "] endIfScope" << std::endl;
}



void Switch::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int condition_reg = context.allocateRegister();
    std::string branch2 = context.allocateJumpBranch();
    std::string end = context.allocateJumpBranch();
    std::string condition = context.reg(condition_reg);

    branchList[0]->RISCOutput(dst, context, condition_reg);
    dst << "beq " << condition << ", zero , ." << branch2 << std::endl;
    branchList[1]->RISCOutput(dst, context, destReg);
    dst << "beq " << " zero , zero , ." << end << std::endl;

  
}

int Switch::getSize() const{
  return branchList[0]->getSize();
}

void Switch::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

