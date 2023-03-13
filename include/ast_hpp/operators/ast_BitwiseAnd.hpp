#ifndef ast_BitwiseAnd_hpp
#define ast_BitwiseAnd_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class BitwiseAnd
 : public Base
{
public:
    //Constructor
    BitwiseAnd(BasePtr left, BasePtr right);

    //Destructor
    virtual ~BitwiseAnd();
    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

    //size
    virtual int getSize() const override;

};

#endif