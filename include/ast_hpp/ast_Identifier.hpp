#ifndef ast_Identifier_hpp
#define ast_Identifier_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class Identifier
 : public Base
{
public:
    //Constructor
    Identifier(std::string IDENTIFIER);

    std::string id;

    //Destructor
    virtual ~Identifier();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual std::string Returnid() const override; 

    virtual int getSize() const override;

    virtual void isFunctionCall(context &context) const override;

};

#endif