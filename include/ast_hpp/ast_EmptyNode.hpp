#ifndef ast_EmptyNode_hpp
#define ast_EmptyNode_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class EmptyNode
 : public Base
{
public:
    //Constructor
    EmptyNode();

    //Destructor
    virtual ~EmptyNode();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

};

#endif