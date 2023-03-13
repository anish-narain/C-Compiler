#ifndef ast_VariableAssign_hpp
#define ast_VariableAssign_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class VariableAssign
 : public Base
{
public:
    //Constructor
    VariableAssign(BasePtr declarator, BasePtr initializer);

    //Destructor
    virtual ~VariableAssign();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

};

#endif