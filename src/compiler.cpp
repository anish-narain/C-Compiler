#include <fstream>
#include <iostream>
#include <unistd.h>
#include "ast.hpp"
#include "cli.h"

void compile(std::ostream &w)
{
    w << ".text" << std::endl;
    w << ".globl f" << std::endl;
    w << std::endl;

    w << "f:" << std::endl;
    w << "addi  t0, zero, 0" << std::endl;
    w << "addi  t0, t0,   5" << std::endl;
    w << "add   a0, zero, t0" << std::endl;
    w << "ret" << std::endl;
}

// TODO: uncomment the below if you're using Flex/Bison.
extern FILE *yyin;

int main(int argc, char **argv)
{
    // Parse CLI arguments, to fetch the values of the source and output files.
    std::string sourcePath = "";
    std::string outputPath = "";
    if (parse_command_line_args(argc, argv, sourcePath, outputPath))
    {
        return 1;
    }

    const Base *ast=parseAST(sourcePath);
    ast->print(std::cout, "  ");

    context c;
    //ast->RISCOutput(std::cout, c, 1);


    // TODO: uncomment the below lines if you're using Flex/Bison.
    // This configures Flex to look at sourcePath instead of
    // reading from stdin.
     yyin = fopen(sourcePath.c_str() , "r"); //added .c_str() to fix datatype issue
     if (yyin == NULL)
     {
         perror("Could not open source file");
         return 1;
     }

    // Open the output file in truncation mode (to overwrite the contents)
    std::ofstream output;
    output.open(outputPath, std::ios::trunc);

    std::cout << std::endl;
    // Compile the input
    std::cout << "Compiling: " << sourcePath << std::endl;
   // compile(output);
    ast->RISCOutput(output, c, 10);
    std::cout << "Compiled to: " << outputPath << std::endl;

    output.close();
    return 0;
}
