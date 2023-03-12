#ifndef ast_VectTypes_hpp
#define ast_VectTypes_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "ast_BaseClass.hpp"

typedef std::vector<BasePtr> build_vector;
// this is used to build a new NodePtr vector
typedef build_vector* VectTypePtr;
// define a pointer to the vector

inline VectTypePtr new_vect(BasePtr vectItem){
    VectTypePtr result = new build_vector;
    result->push_back(vectItem);
    return result;
}

inline VectTypePtr add_to_vect(VectTypePtr origin, BasePtr vectItem){
    origin->push_back(vectItem);
    return origin;
}

#endif