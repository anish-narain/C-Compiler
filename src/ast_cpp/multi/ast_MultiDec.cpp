#include "ast_hpp/multi/ast_MultiDec.hpp"

//Constructor 
MultiDec::MultiDec(BasePtr declaration_specifiers, BasePtr init_declarator_list)
{
    branchList.insert(branchList.end(), {declaration_specifiers, init_declarator_list});
}
//Destructor
MultiDec::~MultiDec()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void MultiDec::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void MultiDec::RISCOutput(std::ostream &dst, int destReg) const
{}