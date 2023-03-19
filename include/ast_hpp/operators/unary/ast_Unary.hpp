#ifndef ast_Unary_hpp
#define ast_Unary_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Unary
 : public Base
{
public:
    //Constructor
    Unary(BasePtr unary_operator, BasePtr cast_expression);

    //Destructor
    virtual ~Unary();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

};

#endif