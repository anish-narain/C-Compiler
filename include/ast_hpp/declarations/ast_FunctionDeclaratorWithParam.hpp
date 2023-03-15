#ifndef ast_FunctionDeclaratorWithParam_hpp
#define ast_FunctionDeclaratorWithParam_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Function_Declarator_With_Param
 : public Base
{
public:
    //Constructor
    Function_Declarator_With_Param(BasePtr direct_declarator, BasePtr parameter_type_list);

    //Destructor
    virtual ~Function_Declarator_With_Param();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual BasePtr returnBranch(int index) const override;

    virtual std::string Returnid() const override;

};

#endif