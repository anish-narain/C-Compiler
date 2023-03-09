#include "ast_hpp/ast_ParamListDeclaration.hpp"

//Constructor 
Param_List_Declarator::Param_List_Declarator(BasePtr parameter_list, BasePtr parameter_declaration)
{
    branchList.insert(branchList.end(), {parameter_list, parameter_declaration});
}
//Destructor
Param_List_Declarator::~Param_List_Declarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Param_List_Declarator::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Function Parameters [" << std::endl;
    branchList[0]->print(dst, indent+"  ");
    branchList[1]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
}

void Param_List_Declarator::RISCOutput(std::ostream &dst, int destReg) const
{}