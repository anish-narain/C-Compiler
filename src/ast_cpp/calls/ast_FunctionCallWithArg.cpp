#include "ast_hpp/calls/ast_FunctionCallWithArg.hpp"

//Constructor 
Function_Call_With_Arguments::Function_Call_With_Arguments(BasePtr postfix_expression, BasePtr argument_expression_list)
{
    branchList.insert(branchList.end(), {postfix_expression, argument_expression_list});
}
//Destructor
Function_Call_With_Arguments::~Function_Call_With_Arguments()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Function_Call_With_Arguments::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Function Call With Arguments [" << std::endl;
    dst << indent << "Function Name = ";
    branchList[0]->print(dst, indent+"  ");
    dst << indent << "Arguments = ";
    branchList[1]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
}

void Function_Call_With_Arguments::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[1]->RISCOutput(dst, context ,destReg);
  dst << "call " << branchList[0]->Returnid() << std::endl;
}

int Function_Call_With_Arguments::getSize() const{
   return branchList[0]->getSize() + branchList[1]->getSize();
}

void Function_Call_With_Arguments::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

