#ifndef ast_ArgDeclaration_hpp
#define ast_ArgDeclaration_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Arg_Declarator
 : public Base
{
public:
    //Constructor
    Arg_Declarator(BasePtr assignment_expression);

    //Destructor
    virtual ~Arg_Declarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

    virtual int GetArgLocation() const override;

    virtual std::string Returnid() const override; 
    
};

#endif