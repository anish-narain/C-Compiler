#ifndef ast_VariableDeclarator_hpp
#define ast_VariableDeclarator_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class VariableDeclarator
 : public Base
{
public:
    //Constructor
    VariableDeclarator(BasePtr declarator);

    //Destructor
    virtual ~VariableDeclarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual std::string Returnid() const override; 

};

#endif