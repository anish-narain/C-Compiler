#ifndef ast_LessThanEqual_hpp
#define ast_LessThanEqual_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class LessThanEqual
 : public Base
{
public:
    //Constructor
    LessThanEqual(BasePtr left, BasePtr right);

    //Destructor
    virtual ~LessThanEqual();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif