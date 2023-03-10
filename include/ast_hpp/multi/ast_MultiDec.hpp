#ifndef ast_MultiDec_hpp
#define ast_MultiDec_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class MultiDec
 : public Base
{
public:
    //Constructor
    MultiDec(BasePtr declaration_specifiers, BasePtr init_declarator_list);

    //Destructor
    virtual ~MultiDec();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, int destReg) const override;

};

#endif