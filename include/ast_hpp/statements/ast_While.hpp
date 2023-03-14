#ifndef ast_While_hpp
#define ast_While_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class While
 : public Base
{
public:
    //Constructor
    While(BasePtr expression, BasePtr statement);

    //Destructor
    virtual ~While();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

   //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;


};

#endif