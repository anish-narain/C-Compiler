#include "ast_hpp/operators/ast_Subtract.hpp"

//Constructor 
Subtract::Subtract(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Subtract::~Subtract()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Subtract::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Subtract Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Subtract::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    branchList[0]->RISCOutput(dst, context, left_reg);
    branchList[1]->RISCOutput(dst, context, right_reg);

    std::string right = context.reg(right_reg);
    std::string left = context.reg(left_reg);

    std::string id = branchList[0]->Returnid();
    std::string type;
    
    if (id == "int") { //if left branch is a constant int instead of a variable int
      type = "int";
    }
    else{
      type = context.returnVarType(id); 
    } 
    
    if (type == "int"){
      dst << "sub " << context.reg(destReg) << ", " << context.reg(left_reg) << ", " << context.reg(right_reg) << std::endl;
    }
    else if (type == "double"){
      dst << "fsub.d f" << context.reg(destReg) << ", f" << context.reg(left_reg) << ", f" << context.reg(right_reg) << std::endl;
    }
    else if (type == "float"){
      dst << "fsub.s f" << context.reg(destReg) << ", f" << context.reg(left_reg) << ", f" << context.reg(right_reg) << std::endl;
    }
}

int Subtract::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void Subtract::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}