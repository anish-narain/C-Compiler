#ifndef ast_MultiFunction_hpp
#define ast_MultiFunction_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class MultiFunction
 : public Base
{
public:
    //Constructor
    MultiFunction(BasePtr declaration_list, BasePtr declaration);

    //Destructor
    virtual ~MultiFunction();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;


};

#endif