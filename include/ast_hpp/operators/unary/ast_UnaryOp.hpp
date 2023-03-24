#ifndef ast_UnaryOp_hpp
#define ast_UnaryOp_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class UnaryOp
 : public Base
{
public:
    //Constructor
    UnaryOp(std::string operation);

    //Destructor
    virtual ~UnaryOp();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    std::string op;

    virtual void createVariableMap(context &context) const override;

    virtual void isFunctionCall(context &context) const override;

    virtual void isPointer(context &context) const override;

    virtual std::string returnOp() const override;

    
};

#endif