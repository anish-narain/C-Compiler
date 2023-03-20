#ifndef ast_NameDeclarator_hpp
#define ast_NameDeclarator_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Name_Declarator
 : public Base
{
public:
    //Constructor
    Name_Declarator(std::string IDENTIFIER);

    std::string id;

    //Destructor
    virtual ~Name_Declarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual std::string Returnid() const override;


};

#endif