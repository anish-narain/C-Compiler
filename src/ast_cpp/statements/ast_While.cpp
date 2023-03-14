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
  branchList[0]->RISCOutput(dst, context, destReg);
  branchList[1]->RISCOutput(dst, context, destReg);
}

int While::getSize() const{
  return branchList[0]->getSize();
}
