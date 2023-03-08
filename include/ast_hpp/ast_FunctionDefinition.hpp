#ifndef ast_FunctionDefiniton_hpp
#define ast_FunctionDefinition_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class Function_Definition
 : public Base
{
public:
    //Constructor
    Function_Definition(BasePtr declaration_specifier, BasePtr declarator, BasePtr compound_statement);

    //Destructor
    virtual ~Function_Definition();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif