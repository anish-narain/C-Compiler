#include "ast_hpp/operators/ast_Add.hpp"

//Constructor 
Add::Add(BasePtr left, BasePtr right)
{
    branchList.insert(branchList.end(), {left, right});
}
//Destructor
Add::~Add()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void Add::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Add Operation" << "[" << std::endl;
  dst << indent << "Left Operator" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "Right Operator" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

void Add::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
 
    int left_reg = context.allocateRegister();
    int right_reg = context.allocateRegister();

    
/*
    if(context.pointer_exists(id) == 1){
      std::cerr << "LHS is pointer" << std::endl;
    }
    else{
      std::cerr << "LHS is NOT pointer" << std::endl;
    }
  */

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

    int multiplier;
    if (type == "int"){
      multiplier = 4;
    }
    else if (type == "float"){
      multiplier = 8;
    }
    else if(type == "double"){
      multiplier = 8;
    }

    if(context.pointer_exists(id) == 1){
      int val = branchList[1]->returnInt();
      dst << "li "<< context.reg(right_reg) << "," << val*multiplier << std::endl;
    }

    std::cerr << type << std::endl; //check if it works

    if (type == "int"){
      dst << "add " << context.reg(destReg) << ", " << context.reg(left_reg) << ", " << context.reg(right_reg) << std::endl;
    }
    else if (type == "double"){
      dst << "fadd.d f" << context.reg(destReg) << ", f" << context.reg(left_reg) << ", f" << context.reg(right_reg) << std::endl;
    }
    else if (type == "float"){
      dst << "fadd.s f" << context.reg(destReg) << ", f" << context.reg(left_reg) << ", f" << context.reg(right_reg) << std::endl;
    }

    context.freedReg(left_reg);
    context.freedReg(right_reg);
 
}

int Add::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void Add::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

std::string Add::Returnid() const{
  return branchList[0]->Returnid();
}