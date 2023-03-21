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
  std::string function_id = branchList[1]->Returnid();
  context.set_function_type(function_id, branchList[0]->getType());
  std::string function_type = context.returnFunctionType(function_id);

  branchList[1]->createParameterMap(context); 
  context.addToFunctionParameters(function_id); 
  context.clearParameterVectors(); 

  //breaks
  branchList[2]->createVariableMap(context);
  context.addToFunctionVariables(function_id);
  context.clearVariableVectors();
  
  dst << ".globl "<< function_id << std::endl; 
  dst << function_id << ":" << std::endl;
  
  dst << "addi sp,sp,-" << stacksize << std::endl;

  
  if (function_type == "double"){
    dst << "sw s0,"<< stacksize - 8 <<"(sp)" << std::endl;
  }
  else{
    dst << "sw s0,"<< stacksize - 4 <<"(sp)" << std::endl;
  }

  
  dst << "addi s0,sp," << stacksize << std::endl; 
  
  int newReg = context.allocateRegister();

  branchList[1]->RISCOutput(dst, context ,newReg);
  branchList[2]->RISCOutput(dst, context ,newReg);

  dst << "." << endFunctionLabel << ":" << std::endl;

  if (function_type == "double"){
    dst << "fmv.d fa0, f" << context.reg(newReg) << std::endl;
    dst << "lw s0,"<< stacksize - 8 <<"(sp)" << std::endl;
  }
  else if (function_type == "float"){
    dst << "fmv.s fa0, f" << context.reg(newReg) << std::endl;
    dst << "lw s0,"<< stacksize - 8 <<"(sp)" << std::endl;
  }
  else{
    dst << "mv a0," << context.reg(newReg) << std::endl;
    dst << "lw s0,"<< stacksize - 4 <<"(sp)" << std::endl;
  }
  
  dst << "addi sp,sp," << stacksize << std::endl;
  dst << "jr ra" << std::endl;
  
}

int Function_Definition::getSize() const
{
  return branchList[1]->getSize() + branchList[2]->getSize();
}

