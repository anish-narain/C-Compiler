#include "ast_hpp/declarations/ast_FunctionDefinition.hpp"

//Constructor 
Function_Definition::Function_Definition(BasePtr declaration_specifier, BasePtr declarator, BasePtr compound_statement)
{
    branchList.insert(branchList.end(), {declaration_specifier, declarator, compound_statement});
}
//Destructor
Function_Definition::~Function_Definition()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Function_Definition::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Function Definition [" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  branchList[1]->print(dst, indent+"  ");
  branchList[2]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Function_Definition::RISCOutput(std::ostream &dst, int destReg) const
{
  branchList[1]->RISCOutput(dst, destReg);
  dst << "addi    sp,sp,-16" << std::endl;
  dst << "sw      s0,12(sp)" << std::endl;
  dst << "addi    s0,sp,16" << std::endl;
  branchList[2]->RISCOutput(dst, destReg);
  dst << "mv      a0,a5" << std::endl;
  dst << "lw      s0,12(sp)" << std::endl;
  dst << "addi    sp,sp,16" << std::endl;
  dst << "jr      ra" << std::endl;
}

int Function_Definition::getSize() const{}