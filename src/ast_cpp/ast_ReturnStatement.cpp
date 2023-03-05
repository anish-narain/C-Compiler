#include "ast_hpp/ast_ReturnStatement.hpp"

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