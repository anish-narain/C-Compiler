#ifndef context_hpp
#define context_hpp
#include <math.h>

class context{
    
public:
    std::map<std::string, int> variable_bindings; //<variable_name, reg>
    std::vector<std::string> labels;
    
    std::map<std::string, std::string> function_types; //<function_name, datatype>
    std::map<std::string, std::map<std::string, std::string>> function_parameters; //<function_name, <parameter_name, datatype>>
    
    std::vector<std::string> parameter_names;
    std::vector<std::string> parameter_types;

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

    int parameterAllocateRegister(){ //searches for the first free register in the range from x10 to x17 and returns its index
        for (int i = 10; i < 17; i++){
            if (Regs[i] == 0 ){
                usedReg(i);
                return i;
        }   
      }
      return -1;
    }

    std::string allocateJumpBranch() {
        static int branch_num = 0;
        branch_num = branch_num+1;
        return "L"+std::to_string(branch_num);
    }

    std::string createLabel() {
        static int label_num = 0;
        label_num = label_num+1;
        std::string labelName = "end"+std::to_string(label_num);
        labels.push_back(labelName);
        return labelName;
    }

    std::string getLabel(){
       return labels.back();
    }

    int rounding(int num){
        int multiplier = ceil((double)num/16);
        return (multiplier*16) + 16;
    }

    // manages statement within a function like ifElse, while, for
    void enterStatement();
    void exitStatement(std::ostream &dst);

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
            return -1;
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

    void set_function_type(std::string id, std::string type){
        function_types[id] = type;
    }

    void set_function_parameters(std::string functionId, std::string parameterName, std::string type){
        function_parameters[functionId][parameterName] = type;
    }

    void addParameterName(std::string name){
        parameter_names.push_back(name);
    }

    void addParameterType(std::string type){
        parameter_types.push_back(type);
    }

    void addToFunctionParameters(std::string functionId){
        for (std::size_t i = 0; i < parameter_names.size(); i++) {
            set_function_parameters(functionId, parameter_names[i], parameter_types[i]);
        }
    }

    void clearParameterVectors(){
        parameter_names.clear();
        parameter_types.clear();
    }

    void printfunction_parameters(std::ostream &dst){
        for (const auto& outer_pair : function_parameters) {
            const std::string& outer_key = outer_pair.first;
            const std::map<std::string, std::string>& inner_map = outer_pair.second;

            dst << "Function: " << outer_key << std::endl;

            // Iterate over each key-value pair in the inner map
            for (const auto& inner_pair : inner_map) {
                const std::string& inner_key = inner_pair.first;
                const std::string& inner_value = inner_pair.second;

                dst << "    " << inner_key << ": " << inner_value << std::endl;
            }
            dst << std::endl;
        }
    }

};

#endif