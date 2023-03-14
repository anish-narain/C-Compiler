#ifndef ast_IfElse_hpp
#define ast_IfElse_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class If_Else
 : public Base
{
public:
    //Constructor
    If_Else(BasePtr expression, BasePtr if_statement, BasePtr else_statement);

    //Destructor
    virtual ~If_Else();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

   //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;


};

#endif