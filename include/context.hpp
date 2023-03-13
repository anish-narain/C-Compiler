#ifndef ast_context_hpp
#define ast_context_hpp
#include <math.h>

class context{
    
public:

struct regfile
{
    int Regs[32] =
    { 1, //x0 zero address
      1, //x1 ra return adress 
      1, 1, //x2 sp stack pointer 
      1, 1, 1, 1, //x3 gp global pointer
      0, 0, 0, 0, 0, 0, 0, 0, //x4 tp 
      1, 1, 1, 1, 1, 1, 1, 1, // 
      0, 0, // 
      1, 1, // 
      1, // 
      1, // 
      1, // 
      1
    }; //    
    
    void useReg(int i) {
        Regs[i] = 1;
    }
    void freeReg(int i){
        Regs[i] = 0;
    }
    int allocate(){
        for (int i = 5; i < 31; i++){
            if (Regs[i] == 0 ){
                useReg (i);
                return i;
        }   
      }
    }
};


};

#endif