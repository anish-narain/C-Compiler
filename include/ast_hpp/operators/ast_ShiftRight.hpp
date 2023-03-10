#ifndef ast_ShiftRight_hpp
#define ast_ShiftRight_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class ShiftRight
 : public Base
{
public:
    //Constructor
    ShiftRight(BasePtr left, BasePtr right);

    //Destructor
    virtual ~ShiftRight();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif