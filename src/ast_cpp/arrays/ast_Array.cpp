#include "ast_hpp/declarations/ast_Array.hpp"

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
  dst << indent << "Array [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}
