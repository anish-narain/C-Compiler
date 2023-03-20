#ifndef ast_Equal_hpp
#define ast_Equal_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Equal
 : public Base
{
public:
    //Constructor
    Equal(BasePtr left, BasePtr right);

    //Destructor
    virtual ~Equal();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //size
    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

};

#endif