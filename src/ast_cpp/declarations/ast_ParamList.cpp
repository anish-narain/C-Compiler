#include "ast_hpp/declarations/ast_ParamList.hpp"

//Constructor 
Param_List::Param_List(BasePtr parameter_list)
{
    branchList.insert(branchList.end(), {parameter_list});
}
//Destructor
Param_List::~Param_List()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Param_List::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Function Parameters [" << std::endl;
    branchList[0]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
}

void Param_List::RISCOutput(std::ostream &dst, int destReg) const
{}