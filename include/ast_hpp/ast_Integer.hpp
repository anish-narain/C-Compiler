#ifndef ast_Integer_hpp
#define ast_Integer_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_BaseClass.hpp"

class Int
 : public Base
{
private:
    int int_value;
public:
    //Constructor
    Int(int val);

    //Destructor
    ~Int();

    //Printing
    void print(std::ostream &dst, std::string indent) const override;

    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

    virtual int getSize() const override;


};

#endif