#include "ast_hpp/types/ast_Array.hpp"

//Constructor 
Array::Array(BasePtr direct_declarator , BasePtr constant_expression)
{
    branchList.insert(branchList.end(), {direct_declarator, constant_expression});
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

void Array::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int Array::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}