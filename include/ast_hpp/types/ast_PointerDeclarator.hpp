#ifndef ast_PointerDeclarator_hpp
#define ast_PointerDeclarator_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class PointerDeclarator
 : public Base
{
public:
    //Constructor
    PointerDeclarator(BasePtr direct_declarator);

    //Destructor
    virtual ~PointerDeclarator();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

};

#endif