
#ifndef ast_FunctionCallWithArg_hpp
#define ast_FunctionCallWithArg_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Function_Call_With_Arguments
 : public Base
{
public:
    //Constructor
    Function_Call_With_Arguments(BasePtr postfix_expression, BasePtr argument_expression_list);

    //Destructor
    virtual ~Function_Call_With_Arguments();

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