#ifndef ast_FunctionNameDeclarator_hpp
#define ast_FunctionNameDeclarator_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class Function_Name_Declarator
 : public Base
{
public:
    //Constructor
    Function_Name_Declarator(std::string IDENTIFIER);

    std::string id;

    //Destructor
    virtual ~Function_Name_Declarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;


};

#endif