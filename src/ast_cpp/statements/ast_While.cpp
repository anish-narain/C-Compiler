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
    std::string branch1 = context.allocateJumpBranch();
    std::string branch2 = context.allocateJumpBranch();
    int zero_reg = context.allocateRegister();
    int start_reg = context.allocateRegister();
    int condition_reg = context.allocateRegister();
    int end_reg = context.allocateRegister();

    std::string zero = context.reg(zero_reg);
    std::string start = context.reg(start_reg);
    dst << "j ." << branch1 << ":" << std::endl;
    dst << "." << branch2 << ":" << std::endl;


    std::string end = context.reg(end_reg);
    branchList[1]->RISCOutput(dst, context, destReg);

    dst << "." << branch2 << ":" << std::endl;
    std::string condition = context.reg(condition_reg);
    branchList[0]->RISCOutput(dst, context, condition_reg);
 
}

int While::getSize() const{
  return branchList[0]->getSize();
}
