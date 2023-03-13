#ifndef ast_ReturnStatement_hpp
#define ast_ReturnStatement_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Return_Statement
 : public Base
{
public:
    //Constructor
    Return_Statement(BasePtr expression);

    //Destructor
    virtual ~Return_Statement();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;

   //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

    virtual int getSize() const override;


};

#endif