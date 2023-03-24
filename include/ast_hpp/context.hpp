#ifndef context_hpp
#define context_hpp
#include <math.h>

class context{
    
public:
    int isFunction = 0;
    std::map<std::string, int> variable_bindings; //<variable_name, reg>
    std::vector<std::string> labels;

    std::map<std::string, std::string> function_types; //<function_name, datatype>
    std::map<std::string, std::map<std::string, std::string>> function_parameters; //<function_name, <parameter_name, datatype>>
    std::map<std::string, std::map<std::string, std::string>> function_variables; //<function_name, <variable_name, datatype>>
    std::map<std::string, std::string> pointer_types; //<pointer_name, pointer_type>
    std::map<std::string, std::string> variableMap_types; //<variable_name, variable_type>

    //Parameter vectors
    std::vector<std::string> parameter_names;
    std::vector<std::string> parameter_types;

    //Variable vectors
    std::vector<std::string> variable_names;
    std::vector<std::string> variable_types;

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
    
    void FunctionCallOccurs(){
        isFunction = 1;
    }

    int ReturnFunctionCallValue(){
        return isFunction;
    }

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

    int implement_var_binding(std::string variable_name, std::string variable_type){
        static int current_stack = -16;
        if (variable_type == "int"){
            current_stack -= 4;
        }
        else if(variable_type == "double"){
            current_stack -= 8;
        }
        else if(variable_type == "float"){
            current_stack -= 8;
        }
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

    //Parameters
    void set_function_parameters(std::string functionId, std::string parameterName, std::string type){
        function_parameters[functionId][parameterName] = type;
        function_variables[functionId][parameterName] = type;//all parameters are also variables
    }

    //Variables
    void set_function_variables(std::string functionId, std::string variableName, std::string type){
        function_variables[functionId][variableName] = type;
        variableMap_types[variableName] = type;
    }

    //Pointers
    void set_pointer_type(std::string pointer_name){
        pointer_types[pointer_name] = variableMap_types[pointer_name];
    }

    //Parameters
    void addParameterName(std::string name){
        parameter_names.push_back(name);
    }
    void addParameterType(std::string type){
        parameter_types.push_back(type);
    }

    //Variables
    void addVariableName(std::string name){
        //std::cerr << "Added names" << std::endl; 
        variable_names.push_back(name);
    }
    void addVariableType(std::string type){
        //std::cerr << "Added types" << std::endl;
        variable_types.push_back(type);
    }

    //Parameters
    void addToFunctionParameters(std::string functionId){
        for (std::size_t i = 0; i < parameter_names.size(); i++) {
            set_function_parameters(functionId, parameter_names[i], parameter_types[i]);
        }
    }

    //Variables
    void addToFunctionVariables(std::string functionId){
        for (std::size_t i = 0; i < variable_names.size(); i++) {
            set_function_variables(functionId, variable_names[i], variable_types[i]);
        }
    }

    //Parameters
    void clearParameterVectors(){
        parameter_names.clear();
        parameter_types.clear();
    }

    //Variables
    void clearVariableVectors(){
        variable_names.clear();
        variable_types.clear();
    }

    std::string returnVarType(const std::string& var_id) {
    // Check if the inner key exists in the global map of maps
            auto outer_it = function_variables.begin();
            while (outer_it != function_variables.end()) {
                const auto& inner_map = outer_it->second;
                auto inner_it = inner_map.find(var_id);
                if (inner_it != inner_map.end()) {
                    // Return the inner value if the inner key is found
                    return inner_it->second;
                }
                ++outer_it;
        }
    
        // If the inner key is not found in any of the inner maps, print an error message and return an empty string
        std::cerr << "Error: Inner key not found." << std::endl;
        return "";
    }

    std::string returnFunctionType(std::string function_name){
        return function_types[function_name];
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

    void printfunction_variables(std::ostream &dst){
        for (const auto& outer_pair : function_variables) {
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

    std::string returnParameterTypesFormat(std::string id){ //would return (int, int) for f(int x, inty)
        std::string inner_values_str = "(";

    // Find the inner map corresponding to the given outer key
        auto inner_map_it = function_parameters.find(id);
        if (inner_map_it != function_parameters.end()) {
            // Iterate over each value in the inner map and append it to the result string
            const std::map<std::string, std::string>& inner_map = inner_map_it->second;
            for (const auto& inner_pair : inner_map) {
                const std::string& inner_value = inner_pair.second;
                inner_values_str += inner_value + ", ";
            }

            // Remove the trailing ", " from the result string
            inner_values_str.erase(inner_values_str.size() - 2);
        }

        inner_values_str += ")";

        return inner_values_str;
    }


};

#endif