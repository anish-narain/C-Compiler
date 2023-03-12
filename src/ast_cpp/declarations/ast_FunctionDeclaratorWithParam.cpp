#include "ast_hpp/declarations/ast_FunctionDeclaratorWithParam.hpp"

//Constructor 
Function_Declarator_With_Param::Function_Declarator_With_Param(BasePtr direct_declarator, BasePtr parameter_type_list)
{
    branchList.insert(branchList.end(), {direct_declarator, parameter_type_list});
}
//Destructor
Function_Declarator_With_Param::~Function_Declarator_With_Param()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Function_Declarator_With_Param::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent+"  ");
    branchList[1]->print(dst, indent+"  ");
}

void Function_Declarator_With_Param::RISCOutput(std::ostream &dst, int destReg) const
{}