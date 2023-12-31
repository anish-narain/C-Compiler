#ifndef ast_Add_hpp
#define ast_Add_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Add
 : public Base
{
public:
    //Constructor
    Add(BasePtr left, BasePtr right);

    //Destructor
    virtual ~Add();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;

    virtual std::string Returnid() const override; 

};

#endif