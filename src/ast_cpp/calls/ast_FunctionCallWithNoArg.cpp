#include "ast_hpp/calls/ast_FunctionCallWithNoArg.hpp"

//Constructor 
Function_Call_With_NoArguments::Function_Call_With_NoArguments(BasePtr postfix_expression)
{
    branchList.insert(branchList.end(), {postfix_expression});
}
//Destructor
Function_Call_With_NoArguments::~Function_Call_With_NoArguments()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void Function_Call_With_NoArguments::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "Function Call With NoArguments [" << std::endl;
    dst << indent << "Function Name = ";
    branchList[0]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
}

void Function_Call_With_NoArguments::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  dst << "call " << branchList[0]->Returnid() << std::endl;
}

int Function_Call_With_NoArguments::getSize() const{
   return branchList[0]->getSize();
}

void Function_Call_With_NoArguments::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
}
