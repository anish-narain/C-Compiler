#include "ast_hpp/ast_BaseClass.hpp"

Base::Base(std::vector<BasePtr> _branchList) //this is a case where you do [new Base(a list of pointers)]
  : branchList(_branchList)
{}

Base::Base() //this is a case where Base() is called with no parameters
  : Base(std::vector<BasePtr>{}) // you refer to the constructor above
  //carrying out "constructor delegation" where you reuse a constructor 
{}


Base::~Base() // Destructor
{
  for(unsigned i = 0; i < branchList.size(); i++){
    delete branchList[i];
  }
}

void Base::print(std::ostream &dst, std::string indent) const{
  dst << indent << "Base Class Reached. ERROR!!! (print)" << std::endl;
}

void Base::RISCOutput(std::ostream &dst, context &context, int destReg) const
{
  dst << "Base Class Reached. ERROR!!! (RISCOutput)" << std::endl;
}

std::string Base::Returnid() const{
  std::cerr << "Base Class Reached. ERROR!!! (ReturnId)" << std::endl;
}

int Base::getSize() const{
  std::cerr << "Base Class Reached. ERROR!!! (getSize)" << std::endl;
  return 0;
}