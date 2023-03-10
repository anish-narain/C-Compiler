#ifndef ast_Multiply_hpp
#define ast_Multiply_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Multiply
 : public Base
{
public:
    //Constructor
    Multiply(BasePtr left, BasePtr right);

    //Destructor
    virtual ~Multiply();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif