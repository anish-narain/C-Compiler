#include "ast_hpp/operators/ast_ValueAssign.hpp"

//Constructor 
ValueAssign::ValueAssign(BasePtr unary_expression, BasePtr assignment_expression)
{
    branchList.insert(branchList.end(), {unary_expression, assignment_expression});
}
//Destructor
ValueAssign::~ValueAssign()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

//Print
void ValueAssign::print(std::ostream &dst, std::string indent) const
{
  dst << indent << "Binary Assignment" << "[" << std::endl;
  dst << indent << "LHS" << std::endl;
  branchList[0]->print(dst, indent+"  ");
  dst << indent << "RHS" << std::endl;
  branchList[1]->print(dst, indent+"  ");
  dst << indent << "]" << std::endl;
}

//void ValueAssign::RISCOutput(std::ostream &dst, context &context, int destReg) const
//{
//    branchList[1]->RISCOutput(dst, context, destReg);
//    std::string id = branchList[0]->Returnid();
//    std::string type = context.returnVarType(id);
//
//    if(type == "double"){
//      if (context.get_var_location(id)== -1){
//        int variableallocate = context.implement_var_binding(id, type);
//        dst << "fsd f" << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
//      }
//      else {
//        int variableallocate = context.get_var_location(id);
//        dst << "fsd f" << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
//      }
//    }
//    if(type == "float"){
//      if (context.get_var_location(id)== -1){
//        int variableallocate = context.implement_var_binding(id, type);
//        dst << "fsw f" << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
//      }
//      else {
//        int variableallocate = context.get_var_location(id);
//        dst << "fsw f" << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
//      }
//    }
//    else{
//      if (context.get_var_location(id)== -1){
//        int variableallocate = context.implement_var_binding(id, type);
//        dst << "sw " << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
//      }
//
//      else {
//        int variableallocate = context.get_var_location(id);
//        dst << "sw " << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
//      }
//    }
//
//     
//}

int ValueAssign::getSize() const{
  return branchList[0]->getSize() + branchList[1]->getSize();
}

void ValueAssign::createVariableMap(context &context) const{
  branchList[0]->createVariableMap(context);
  branchList[1]->createVariableMap(context);
}

void ValueAssign::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
    branchList[0]->RISCOutput(dst, context, destReg);
    branchList[1]->RISCOutput(dst, context, destReg);
    std::string id = branchList[0]->Returnid();
    std::string type = context.returnVarType(id);

    if (context.get_var_location(id)== -1){
      int variableallocate = context.implement_var_binding(id, type);
      dst << "sw " << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
    }
    else {
      int variableallocate = context.get_var_location(id);
      dst << "sw " << context.reg(destReg) <<  ", " << variableallocate << "(s0)" <<std::endl;
    }

}

std::string ValueAssign::Returnid() const{
  return branchList[0]->Returnid()+branchList[1]->Returnid();
}

void ValueAssign::isPointer(context &context) const{
  branchList[0]->isPointer(context);
  branchList[1]->isPointer(context);
}