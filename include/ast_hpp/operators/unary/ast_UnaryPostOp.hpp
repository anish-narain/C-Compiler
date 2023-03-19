#ifndef ast_UnaryPostOp_hpp
#define ast_UnaryPostOp_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class UnaryPostOp
 : public Base
{
public:
    //Constructor
    UnaryPostOp(BasePtr postfix_expression, std::string operation);

    //Destructor
    virtual ~UnaryPostOp();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    std::string op;
};

#endif