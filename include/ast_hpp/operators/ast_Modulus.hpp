#ifndef ast_Modulus_hpp
#define ast_Modulus_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Modulus
 : public Base
{
public:
    //Constructor
    Modulus(BasePtr left, BasePtr right);

    //Destructor
    virtual ~Modulus();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif