#ifndef ast_ValueAssign_hpp
#define ast_ValueAssign_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class ValueAssign
 : public Base
{
public:
    //Constructor
    ValueAssign(BasePtr unary_expression, BasePtr assignment_expression);

    //Destructor
    virtual ~ValueAssign();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;

    virtual void createParameterMap(context &context) const override;

};

#endif