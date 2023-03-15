#ifndef context_hpp
#define context_hpp
#include <math.h>

class context{
    
public:
    std::map<std::string, int> variable_bindings;

    int Regs[32] =
    { 1, //x0 zero address: index = 0 
      1, //x1 ra return address: index = 1
      1,  //x2 sp stack pointer: index = 2
      1,  //x3 gp global pointer: index = 3
      1, // Thread pointer: index = 4
      0, 0, 0,  //t0-t2 Temporary registers: index = 5-7 
      1, 1,  //s0-s1 Callee-saved registers: index = 8-9
      0, 0, 0, 0, 0, 0, 0, 0, //a0-a7 Argument registers: index = 10-17
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, //s2-s11 Callee-saved registers: index = 18-27
      0, 0, 0, 0, //t3-t6 Temporary registers: index = 28-31
    };  
    
    void usedReg(int i) {
        Regs[i] = 1;
    }
    void freedReg(int i){
        Regs[i] = 0;
    }
    int allocateRegister(){ //searches for the first free register in the range from x5 to x31 and returns its index
        for (int i = 5; i < 31; i++){
            if (Regs[i] == 0 ){
                usedReg(i);
                return i;
        }   
      }
      return -1;
    }

    int parameterAllocateRegister(){ //searches for the first free register in the range from x5 to x31 and returns its index
        for (int i = 10; i < 17; i++){
            if (Regs[i] == 0 ){
                usedReg(i);
                return i;
        }   
      }
      return -1;
    }

    int rounding(int num){
        int multiplier = ceil((double)num/16);
        return (multiplier*16) + 16;
    }

    int implement_var_binding(std::string variable_name){
        static int current_stack = -16;
        current_stack -= 4;
        variable_bindings[variable_name] = current_stack;
        return current_stack;
    }

    int get_var_location(std::string variable_name) const {
        auto it = variable_bindings.find(variable_name);
        if (it == variable_bindings.end()) {
            std::cerr << "Variable not found" << std::endl;
        }
        return it->second; // return the second item from the map[name
    }


    std::string reg(int i){
        if (i > 4 && i < 8) /*From i = 5 to 7*/{
            return 't' + std::to_string(i-5);
        }
        else if (i > 9 && i < 18) /*From i = 10 to 17*/{
            return 'a' + std::to_string(i-10);
        }
        else if (i > 27 && i < 32) /*From i = 28 to 31*/{
            return 't' + std::to_string(i-25);
        }
    }
};

#endif