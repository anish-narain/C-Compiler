#include "ast_hpp/multi/ast_MultiDeclaration.hpp"

//Constructor 
MultiDeclaration::MultiDeclaration(BasePtr declaration_list, BasePtr declaration)
{
    branchList.insert(branchList.end(), {declaration_list, declaration});
}
//Destructor
MultiDeclaration::~MultiDeclaration()
{
  for (auto branch : branchList) {
    delete branch;
  }
}

void MultiDeclaration::print(std::ostream &dst, std::string indent) const
{
    branchList[0]->print(dst, indent);
    branchList[1]->print(dst, indent);
}

void MultiDeclaration::RISCOutput(std::ostream &dst, int destReg) const
{}

int MultiDeclaration::getSize() const{}