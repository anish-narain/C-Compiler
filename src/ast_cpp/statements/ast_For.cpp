#include "ast_hpp/statements/ast_For.hpp"

//Constuctor
For::For(BasePtr initialize, BasePtr condition, BasePtr increment, BasePtr statement);
{
    branchList.insert(branchList.end(), {iniitialize, condition, increment, statement});
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
  branchList[0]->RISCOutput(dst, context, destReg);
  branchList[1]->RISCOutput(dst, context, destReg);
  branchList[2]->RISCOutput(dst, context, destReg);
  branchList[3]->RISCOutput(dst, context, destReg);
}

int For::getSize() const{
  return branchList[0]->getSize();
}
