#include "ast_hpp/multi/ast_MultiFunction.hpp"

//Constructor 
MultiFunction::MultiFunction(BasePtr translation_unit, BasePtr external_declaration)
{
    branchList.insert(branchList.end(), {translation_unit, external_declaration});
}
//Destructor
MultiFunction::~MultiFunction()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void MultiFunction::print(std::ostream &dst, std::string indent) const
{
    dst << indent << "New Function [" << std::endl;
    branchList[0]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
    dst << indent << "New Function [" << std::endl;
    branchList[1]->print(dst, indent+"  ");
    dst << indent << "]" << std::endl;
}

void MultiFunction::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  branchList[0]->RISCOutput(dst, context ,destReg);
  branchList[1]->RISCOutput(dst, context ,destReg);
}

int MultiFunction::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void MultiFunction::isFunctionCall(context &context) const{
  std::cerr << "AFunctionCall" << std::endl;
  branchList[0]->isFunctionCall(context);
  branchList[1]->isFunctionCall(context);
}

void MultiFunction::isPointer(context &context) const{
    branchList[0]->isPointer(context);
    branchList[1]->isPointer(context);
}