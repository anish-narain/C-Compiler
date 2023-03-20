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

BasePtr Function_Definition::returnBranch(int index) const{
  return branchList[index];
}

void Function_Definition::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  int stacksize = context.rounding(getSize()); 
  std::string endFunctionLabel = context.createLabel();
  std::string id = branchList[1]->Returnid();
  context.set_function_type(id, branchList[0]->getType());

  branchList[1]->createParameterMap(context); 
  context.addToFunctionParameters(id); 
  context.clearParameterVectors(); 

  //breaks
  branchList[2]->createVariableMap(context);
  context.addToFunctionVariables(id);
  context.clearVariableVectors();
  
  dst << ".globl "<< id << std::endl; 
  dst << id << ":" << std::endl;
  
  dst << "addi sp,sp,-" << stacksize << std::endl;
  dst << "sw s0,"<< stacksize - 4 <<"(sp)" << std::endl;
  dst << "addi s0,sp," << stacksize << std::endl; 
  
  int newReg = context.allocateRegister();

  branchList[1]->RISCOutput(dst, context ,newReg);
  branchList[2]->RISCOutput(dst, context ,newReg);

  dst << "." << endFunctionLabel << ":" << std::endl;
  dst << "mv a0," << context.reg(newReg) << std::endl;
  dst << "lw s0,"<< stacksize - 4 <<"(sp)" << std::endl;
  dst << "addi sp,sp," << stacksize << std::endl;
  dst << "jr ra" << std::endl;
  
}

int Function_Definition::getSize() const
{
  return branchList[1]->getSize() + branchList[2]->getSize();
}

