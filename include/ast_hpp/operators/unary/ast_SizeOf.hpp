#ifndef ast_SizeOf_hpp
#define ast_SizeOf_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class SizeOf
 : public Base
{
public:
    //Constructor
    SizeOf(BasePtr value);

    //Destructor
    virtual ~SizeOf();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    /*virtual void createParameterMap(context &context) const override;*/

};

#endif
