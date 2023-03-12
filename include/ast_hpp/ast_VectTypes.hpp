#ifndef ast_VectTypes_hpp
#define ast_VectTypes_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "ast_BaseClass.hpp"

typedef std::vector<BasePtr> vect;
// this is used to build a new NodePtr vector
typedef vect* VectTypePtr;
// define a pointer to the vector

inline VectTypePtr new_vect(BasePtr vectItem){
    VectTypePtr result = new vect;
    result->push_back(vectItem);
    return result;
}

inline VectTypePtr add_to_vect(VectTypePtr origin, BasePtr vectItem){
    origin->push_back(vectItem);
    return origin;
}

#endif