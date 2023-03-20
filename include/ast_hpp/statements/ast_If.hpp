#ifndef ast_If_hpp
#define ast_If_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class If
 : public Base
{
public:
    //Constructor
    If(BasePtr expression, BasePtr if_statement);

    //Destructor
    virtual ~If();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

   //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;


};

#endif