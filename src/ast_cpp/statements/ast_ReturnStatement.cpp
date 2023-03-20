#include "ast_hpp/statements/ast_ReturnStatement.hpp"

//Constuctor
Return_Statement::Return_Statement(BasePtr expression)
{
    branchList.insert(branchList.end(), {expression});
}

//Destructor
Return_Statement::~Return_Statement()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Return_Statement::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Return: [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Return_Statement::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context, destReg);
  dst << "j ." << context.getLabel() << std::endl;
}

void Return_Statement::createParameterMap(context &context) const{
  branchList[0]->createParameterMap(context);
}

int Return_Statement::getSize() const{
  return branchList[0]->getSize();
}