#ifndef ast_Multiline_hpp
#define ast_Multiline_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Multiline
 : public Base
{
public:
    //Constructor
    Multiline(BasePtr declaration_list, BasePtr statement_list);

    //Destructor
    virtual ~Multiline();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

    virtual void isFunctionCall(context &context) const override;

    virtual void isPointer(context &context) const override;

};

#endif