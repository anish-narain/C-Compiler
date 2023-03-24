#include "ast_hpp/operators/pointer/ast_PointerDeclarator.hpp"

//Constructor 
PointerDeclarator::PointerDeclarator(BasePtr pointer, BasePtr direct_declarator)
{
    branchList.insert(branchList.end(), {pointer, direct_declarator});
}
//Destructor
PointerDeclarator::~PointerDeclarator()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void PointerDeclarator::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Pointer Declarator [" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void PointerDeclarator::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    branchList[0]->RISCOutput(dst, context, destReg);
    branchList[1]->RISCOutput(dst, context, destReg);
    
}

void PointerDeclarator::isFunctionCall(context &context) const
{
    branchList[1]->isFunctionCall(context);
}

std::string PointerDeclarator::Returnid() const{
  return branchList[1]->Returnid();
}

int PointerDeclarator::getSize() const{
  return branchList[0]->getSize()+branchList[1]->getSize();
}

void PointerDeclarator::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

void PointerDeclarator::isPointer(context &context) const{
  std::cerr <<" is a pointer" << std::endl;
  std::string pointer_name = branchList[1]->Returnid();
  context.set_pointer_type(pointer_name);
  std::cerr << pointer_name << " is a pointer" << std::endl;
}