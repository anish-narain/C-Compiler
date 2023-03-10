#include "ast_hpp/multi/ast_Multiline.hpp"

//Constructor 
Multiline::Multiline(BasePtr declaration_list, BasePtr statement_list)
{
    branchList.insert(branchList.end(), {declaration_list, statement_list});
}
//Destructor
Multiline::~Multiline()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Multiline::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Compound Statements [" << std::endl;
    branchList[0]->print(dst, indent+"  ");
    branchList[1]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
}

void Multiline::RISCOutput(std::ostream &dst, int destReg) const
{}