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
    dst << "lw a4, " << context.reg(destReg) << "(s0)" <<std::endl;
    dst << "li a5, 1"<< std::endl;
    dst << "beq   a4,a5,.L2" << std::endl;
    dst << "lw a4, " << context.reg(destReg) << "(s0)" <<std::endl;
    dst << "li a5, 2"<< std::endl;
    dst << "beq   a4,a5,.L3" << std::endl;
    dst << "j       .L6" << std::endl;
    dst << ".L2: " << std::endl;
    dst << "li      a5,10" << std::endl;
    dst << "j       .L1" << std::endl;
    dst << ".L3: " << std::endl;
    dst << "li      a5,11" << std::endl;
    dst << "j       .L1" << std::endl;
    dst << ".L6: " << std::endl;
    dst << ".L1: " << std::endl;

  
}

int Switch::getSize() const{
  return branchList[0]->getSize();
}

void Switch::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

