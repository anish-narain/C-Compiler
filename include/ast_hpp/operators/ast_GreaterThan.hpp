#ifndef ast_GreaterThan_hpp
#define ast_GreaterThan_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class GreaterThan
 : public Base
{
public:
    //Constructor
    GreaterThan(BasePtr left, BasePtr right);

    //Destructor
    virtual ~GreaterThan();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

    //size
    virtual int getSize() const override;

};

#endif