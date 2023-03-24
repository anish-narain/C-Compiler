#include "ast_hpp/multi/ast_MultiStatement.hpp"

//Constructor 
MultiStatement::MultiStatement(BasePtr statement_list, BasePtr statement)
{
    branchList.insert(branchList.end(), {statement_list, statement});
}
//Destructor
MultiStatement::~MultiStatement()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void MultiStatement::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void MultiStatement::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int MultiStatement::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void MultiStatement::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

void MultiStatement::isFunctionCall(context &context) const{
  std::cerr << "CFunctionCall" << std::endl;
  branchList[0]->isFunctionCall(context);
  branchList[1]->isFunctionCall(context);
}

void MultiStatement::isPointer(context &context) const{
  branchList[0]->isPointer(context);
  branchList[1]->isPointer(context);
}