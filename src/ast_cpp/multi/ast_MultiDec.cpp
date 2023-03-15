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
    //dst << "Reached" << std::endl;
    branchList[0]->print(dst, indent);
    //dst << "Passing throug declaration specifier" << std::endl;
    branchList[1]->print(dst, indent);
    //dst << "Passing throug init_declarator" << std::endl;
}

void MultiDec::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int MultiDec::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}