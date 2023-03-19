#ifndef ast_ArgListDeclaration_hpp
#define ast_ArgListDeclaration_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Arg_List_Declarator
 : public Base
{
public:
    //Constructor
    Arg_List_Declarator(BasePtr argument_expression_list, BasePtr assignment_expression);

    //Destructor
    virtual ~Arg_List_Declarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

};

#endif