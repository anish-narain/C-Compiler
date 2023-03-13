#ifndef ast_MultiDeclaration_hpp
#define ast_MultiDeclaration_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class MultiDeclaration
 : public Base
{
public:
    //Constructor
    MultiDeclaration(BasePtr declaration_list, BasePtr declaration);

    //Destructor
    virtual ~MultiDeclaration();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;

};

#endif