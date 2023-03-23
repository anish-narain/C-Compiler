#ifndef ast_FunctionCallWithNoArg_hpp
#define ast_FunctionCallWithNoArg_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Function_Call_With_NoArguments
 : public Base
{
public:
    //Constructor
    Function_Call_With_NoArguments(BasePtr postfix_expression);

    //Destructor
    virtual ~Function_Call_With_NoArguments();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

    virtual void isFunctionCall(context &context) const override;

};

#endif