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

void MultiStatement::RISCOutput(std::ostream &dst, int destReg) const
{}

int MultiStatement::getSize() const{}