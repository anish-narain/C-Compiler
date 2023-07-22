# C-Compiler #

<img width="550" alt="image" src="https://github.com/anish-narain/C-Compiler/assets/69715492/247b9186-f892-46c0-86de-5d4d3c5188ec">

In this project, significant progress was made by achieving several milestones. The project started with the utilization of a template lexer and parser obtained from https://www.lysator.liu.se/c/ANSI-C-grammar-y.html and https://www.lysator.liu.se/c/ANSI-C-grammar-l.html, which were adapted to meet the specific requirements. With the parser structure in place, Abstract Syntax Trees (ASTs) were successfully created for various basic test cases.

The process of building the ASTs involved the creation of header (.hpp) and implementation (.cpp) files, with Object-Oriented Programming (OOP) concepts like classes, constructors, methods, and inheritance being utilized. By employing inheritance, a hierarchical structure was established for representing the AST nodes, where the base node class was inherited by other classes.

After the successful construction of the ASTs, the next milestone involved the implementation of code generation for the corresponding RISC-V assembly code. To achieve this, a context was designed and maintained, which was passed through all the classes. This context was responsible for keeping track of crucial information, such as the stack and frame pointer, variable and parameter declarations, and other relevant details required during the code generation process.

In summary, the following key aspects were accomplished during this progress:

1. Template adaptation: The template lexer and parser files were used as a starting point and modified to suit the project's specific requirements.
2. Abstract Syntax Trees (ASTs): ASTs were successfully created to represent the parsed C code in a structured manner, laying the foundation for further processing and code generation.
3. Object-Oriented Programming (OOP) concepts: OOP principles, including classes, constructors, methods, and inheritance, were efficiently applied to implement the AST nodes and improve the organization of the code.
4. Code generation for RISC-V: A robust process was developed to generate RISC-V assembly code from the constructed ASTs, allowing for the translation of C code into executable RISC-V machine code.
5. Context handling: A context mechanism was implemented to manage and propagate essential information throughout the code generation process, ensuring the generation of correct and coherent RISC-V assembly output.

Project Management was a key contributor to the success of this project. NotionRecording is a recording, displaying how concepts of scrum and sprint planning were implemented using Notion.


