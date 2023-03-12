 #ifndef ast_Array_hpp
#define ast_Array_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Array
 : public Base
{
public:
    //Constructor
    Array(BasePtr direct_declarator , BasePtr constant_expression);

    //Destructor
    virtual ~Array();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif