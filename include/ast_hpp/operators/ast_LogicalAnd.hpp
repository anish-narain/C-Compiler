#ifndef ast_LogicalAnd_hpp
#define ast_LogicalAnd_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class LogicalAnd
 : public Base
{
public:
    //Constructor
    LogicalAnd(BasePtr left, BasePtr right);

    //Destructor
    virtual ~LogicalAnd();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

    //size
    virtual int getSize() const override;
};

#endif
