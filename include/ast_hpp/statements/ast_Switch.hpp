#ifndef ast_Switch_hpp
#define ast_Switch_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Switch
 : public Base
{
public:
    //Constructor
    Switch(BasePtr expression, BasePtr statement);

    //Destructor
    virtual ~Switch();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

   //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;

    virtual void createVariableMap(context &context) const override;



};

#endif