#ifndef ast_GreaterThanEqual_hpp
#define ast_GreaterThanEqual_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class GreaterThanEqual
 : public Base
{
public:
    //Constructor
    GreaterThanEqual(BasePtr left, BasePtr right);

    //Destructor
    virtual ~GreaterThanEqual();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif