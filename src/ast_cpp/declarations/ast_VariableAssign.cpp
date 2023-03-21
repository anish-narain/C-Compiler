#include "ast_hpp/declarations/ast_VariableAssign.hpp"

//Constructor 
VariableAssign::VariableAssign(BasePtr declaration, BasePtr initializer)
{
    branchList.insert(branchList.end(), {declaration, initializer});
}
//Destructor
VariableAssign::~VariableAssign()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void VariableAssign::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Variable Assign [" << std::endl;
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
    dst << indent << "]" << std::endl;
}

void VariableAssign::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
  std::string var_name = branchList[0]->Returnid();
  std::string var_type = context.returnVarType(var_name);
  int variableallocate = context.implement_var_binding(var_name, var_type);
  dst << "sw " << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
}

int VariableAssign::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

/*
void VariableAssign::createParameterMap(context &context) const{
  branchList[0]->createParameterMap(context);
  branchList[1]->createParameterMap(context);
}
*/

/*
void VariableAssign::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
}
*/

std::string VariableAssign::Returnid() const{
  return branchList[0]->Returnid();
}