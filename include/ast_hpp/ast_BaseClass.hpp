#ifndef ast_BaseClass_hpp
#define ast_BaseClass_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

//#include "context.hpp" //don't need this yet

class Base;

typedef Base* BasePtr;
class Base
{
protected:
  std::vector<BasePtr> branchList; //list called branchList (which stores all the node pointers)

public:
  // Constructors
  Base(std::vector<BasePtr> _branchList); 
  Base();
 //Base(std::vector<BasePtr> branchList1, std::vector<BasePtr> branchList2); // Specifically used for sequence

  //print statement
  virtual void print(std::ostream &dst, std::string indent) const =0;

  // Destructor
  virtual ~Base();

};


#endif