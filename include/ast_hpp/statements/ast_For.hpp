#ifndef ast_For_hpp
#define ast_For_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class For
 : public Base
{
public:
    //Constructor
    For(BasePtr initialize, BasePtr condition, BasePtr increment, BasePtr statement);

    //Destructor
    virtual ~For();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

   //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    virtual int getSize() const override;


};

#endif

