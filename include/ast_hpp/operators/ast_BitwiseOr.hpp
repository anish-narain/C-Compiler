#ifndef ast_BitwiseOr_hpp
#define ast_BitwiseOr_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class BitwiseOr
 : public Base
{
public:
    //Constructor
    BitwiseOr(BasePtr left, BasePtr right);

    //Destructor
    virtual ~BitwiseOr();
    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //size
    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

};

#endif