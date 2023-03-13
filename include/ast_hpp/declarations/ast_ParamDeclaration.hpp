#ifndef ast_ParamDeclaration_hpp
#define ast_ParamDeclaration_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Param_Declarator
 : public Base
{
public:
    //Constructor
    Param_Declarator(BasePtr declaration_specifier, BasePtr declarator);

    //Destructor
    virtual ~Param_Declarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

};

#endif