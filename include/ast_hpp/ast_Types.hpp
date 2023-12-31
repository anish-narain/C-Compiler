#ifndef ast_Types_hpp
#define ast_Types_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class Types
 : public Base
{
public:
    //Constructor
    Types(std::string dataType);

    //Destructor
    virtual ~Types();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

    std::string type;

    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //size
    virtual int getSize() const override;

    virtual std::string getType() const override;

    virtual void isFunctionCall(context &context) const override;

    virtual void isPointer(context &context) const override;

};

#endif