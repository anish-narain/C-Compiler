#ifndef ast_MultiStatement_hpp
#define ast_MultiStatement_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class MultiStatement
 : public Base
{
public:
    //Constructor
    MultiStatement(BasePtr statement_list, BasePtr statement);

    //Destructor
    virtual ~MultiStatement();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

    virtual int isFunctionCall() const override;
};

#endif