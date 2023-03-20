#include "ast_hpp/declarations/ast_ParamDeclaration.hpp"

//Constructor 
Param_Declarator::Param_Declarator(BasePtr declaration_specifier, BasePtr declarator)
{
    branchList.insert(branchList.end(), {declaration_specifier, declarator});
}
//Destructor
Param_Declarator::~Param_Declarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Param_Declarator::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void Param_Declarator::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  std::string var_id = branchList[1]->Returnid();
  std::string var_type = branchList[0]->getType();

  context.addParameterName(var_id);
  context.addParameterType(var_type);

  int var_addr = context.implement_var_binding(var_id);
  int param_reg = context.parameterAllocateRegister();

  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);

  dst << "sw " << context.reg(param_reg) << ", " << var_addr << "(s0)" <<std::endl;
}


int Param_Declarator::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}