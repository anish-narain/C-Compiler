#ifndef ast_Divide_hpp
#define ast_Divide_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Divide
 : public Base
{
public:
    //Constructor
    Divide(BasePtr left, BasePtr right);

    //Destructor
    virtual ~Divide();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif