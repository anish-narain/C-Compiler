#include "ast_hpp/types/ast_Array.hpp"

//Constructor 
Array::Array(BasePtr direct_declarator , BasePtr constant_expression)
{
    branchList.insert(branchList.end(), {});
}
//Destructor
Array::~Array()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Array::print(std::ostream &dst, std::string indent) const
{
  //branchList[0]->print(dst, indent+"  ");
  dst << indent << "Array [" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Array::RISCOutput(std::ostream &dst, int destReg) const
{}