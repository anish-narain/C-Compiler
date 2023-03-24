#ifndef ast_ParamListDeclaration_hpp
#define ast_ParamListDeclaration_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Param_List_Declarator
 : public Base
{
public:
    //Constructor
    Param_List_Declarator(BasePtr parameter_list, BasePtr parameter_declaration);

    //Destructor
    virtual ~Param_List_Declarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual void createParameterMap(context& context) const override;

    virtual void isPointer(context &context) const override;

};

#endif