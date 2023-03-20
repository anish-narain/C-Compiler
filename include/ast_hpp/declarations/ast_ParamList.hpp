#ifndef ast_ParamList_hpp
#define ast_ParamList_hpp
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast_hpp/ast_BaseClass.hpp"

class Param_List
 : public Base
{
public:
    //Constructor
    Param_List(BasePtr parameter_list);

    //Destructor
    virtual ~Param_List();

    //Printing
    virtual void print(std::ostream &dst, std::string indent) const override;
    
    //Code gen
    void RISCOutput(std::ostream &dst, context &context, int destReg) const override;

    //Size 
    virtual int getSize() const override;

    virtual void createParameterMap(context &context) const override;
};

#endif