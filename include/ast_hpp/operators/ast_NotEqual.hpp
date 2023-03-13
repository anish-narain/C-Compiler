#ifndef ast_NotEqual_hpp
#define ast_NotEqual_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class NotEqual
 : public Base
{
public:
    //Constructor
    NotEqual(BasePtr left, BasePtr right);

    //Destructor
    virtual ~NotEqual();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //size
    virtual int getSize() const override;
};

#endif