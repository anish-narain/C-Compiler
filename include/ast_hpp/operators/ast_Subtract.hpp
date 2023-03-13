#ifndef ast_Subtract_hpp
#define ast_Subtract_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Subtract
 : public Base
{
public:
    //Constructor
    Subtract(BasePtr left, BasePtr right);

    //Destructor
    virtual ~Subtract();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //size
    virtual int getSize() const override;

};

#endif