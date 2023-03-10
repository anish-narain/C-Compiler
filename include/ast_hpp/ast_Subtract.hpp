#ifndef ast_Sub_hpp
#define ast_Sub_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class Sub
 : public Base
{
public:
    //Constructor
    Sub(BasePtr left, BasePtr right);

    //Destructor
    virtual ~Sub();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif