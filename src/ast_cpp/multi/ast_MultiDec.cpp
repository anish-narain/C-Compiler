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

void MultiDec::RISCOutput(std::ostream &dst, int destReg) const
{}

int MultiDec::getSize() const{}