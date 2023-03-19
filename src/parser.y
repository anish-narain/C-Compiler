%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern Base *g_root; // A way of getting the AST out
  extern FILE *yyin;
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

%union{
  BasePtr base; //will come in our version of ast.hpp
  //VectPtr vect; //will come in our version of "List.hpp"
  int int_num;
  double float_num;
  std::string *string;
  yytokentype token;
}

//TOKENS ===================================================================
%token T_INT T_FLOAT

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN 

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN


//TYPES ===================================================================
%type <base> primary_expression unary_expression postfix_expression
%type <base> multiplicative_expression additive_expression shift_expression
%type <base> relational_expression equality_expression and_expression
%type <base> exclusive_or_expression inclusive_or_expression logical_and_expression
%type <base> logical_or_expression conditional_expression assignment_expression
%type <base> expression constant_expression

%type <base> declaration declaration_specifiers init_declarator
%type <base> type_specifier struct_specifier struct_declaration
%type <base> struct_declarator declarator enum_specifier enumerator
%type <base> pointer direct_declarator abstract_declarator direct_abstract_declarator

%type <base> parameter_declaration type_name initializer
%type <base> statement labeled_statement compound_statement expression_statement
%type <base> selection_statement iteration_statement jump_statement external_declaration
%type <base> function_definition cast_expression

%type <base> translation_unit declaration_list specifier_qualifier_list
%type <base> struct_declaration_list struct_declarator_list enumerator_list
%type <base> argument_expression_list IDENTIFIER_list initializer_list
%type <base> statement_list parameter_type_list parameter_list init_declarator_list unary_operator

%type <int_num> T_INT
%type <string> IDENTIFIER

%start StartTree
%%
StartTree: translation_unit {g_root = $1; }

translation_unit
	: external_declaration { $$ = $1; }
	| translation_unit external_declaration 
	;

external_declaration 
	: function_definition { $$ = $1; }
	| declaration { $$ = $1; }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement {$$ = new Function_Definition($1, $2, $3);} 
	| declarator declaration_list compound_statement
	| declarator compound_statement 
	;


declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier {$$ = $1;}  
	| type_specifier declaration_specifiers 
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

declarator
	: pointer direct_declarator
	| direct_declarator {$$ = $1;}  
	;

direct_declarator
	: IDENTIFIER  {$$ = new Name_Declarator(*$1); delete $1;}  
	| '(' declarator ')' {$$ = $2;}
	| direct_declarator '[' constant_expression ']' {$$ = new Array($1, $3);}
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')' {$$ = new Function_Declarator_With_Param($1, $3);} 
	| direct_declarator '(' IDENTIFIER_list ')'
	| direct_declarator '(' ')'{$$ = $1;} 
	;

compound_statement
	: '{' '}' {$$ = new EmptyNode();} 
	| '{' statement_list '}' {$$ = $2;} 
	| '{' declaration_list '}' {$$ = $2;}
	| '{' declaration_list statement_list '}' {$$ = new Multiline($2, $3);}
	;

type_specifier
	: VOID { $$ = new Types("void");}
	| CHAR { $$ = new Types("char");}
	| SHORT { $$ = new Types("short");}
	| INT { $$ = new Types("int");}
	| LONG { $$ = new Types("long");}
	| FLOAT { $$ = new Types("float");}
	| DOUBLE { $$ = new Types("double");}
	| SIGNED { $$ = new Types("signed");}
	| UNSIGNED { $$ = new Types("unsigned");}
	| struct_or_union_specifier
	| enum_specifier
	| type_name
	;

statement_list
	: statement {$$ = $1;} 
	| statement_list statement {$$ = new MultiStatement($1, $2);}
	;

statement
	: labeled_statement
	| compound_statement {$$ = $1;}
	| expression_statement {$$ = $1;}
	| selection_statement {$$ = $1;}
	| iteration_statement {$$ = $1;}
	| jump_statement {$$ = $1;} 
	;

expression_statement
	: ';'
	| expression ';' {$$ = $1;}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';' {$$ = new Return_Statement($2);} 
	;

expression
	: assignment_expression {$$ = $1;}
	| expression ',' assignment_expression
	;

assignment_expression
	: conditional_expression {$$ = $1;}
	| unary_expression '=' assignment_expression { $$ = new ValueAssign($1, $3);}
	;

conditional_expression
	: logical_or_expression {$$ = $1;}
	| logical_or_expression '?' expression ':' conditional_expression
	;

logical_or_expression
	: logical_and_expression {$$ = $1;}
	| logical_or_expression OR_OP logical_and_expression {$$ = new LogicalOr($1, $3);}
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression {$$ = new LogicalAnd($1, $3);}
	;

inclusive_or_expression
	: exclusive_or_expression {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression {$$ = new BitwiseOr($1, $3);}
	;

exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression {$$ = new BitwiseXor($1, $3);}
	;

and_expression
	: equality_expression {$$ = $1;} 
	| and_expression '&' equality_expression  {$$ = new BitwiseAnd($1, $3);}
	;

equality_expression
	: relational_expression {$$ = $1;}
	| equality_expression EQ_OP relational_expression  {$$ = new Equal($1, $3);} 
	| equality_expression NE_OP relational_expression {$$ = new NotEqual($1, $3);} //added
	;

relational_expression
	: shift_expression {$$ = $1;}
	| relational_expression '<' shift_expression {$$ = new LessThan($1, $3);}
	| relational_expression '>' shift_expression {$$ = new GreaterThan($1, $3);}
	| relational_expression LE_OP shift_expression {$$ = new LessThanEqual($1, $3);}
	| relational_expression GE_OP shift_expression {$$ = new GreaterThanEqual($1, $3);}
	;

shift_expression 
	: additive_expression {$$ = $1;}
	| shift_expression LEFT_OP additive_expression {$$ = new ShiftLeft($1, $3);} //added
	| shift_expression RIGHT_OP additive_expression {$$ = new ShiftRight($1, $3);} //added
	;

additive_expression
	: multiplicative_expression {$$ = $1;}
	| additive_expression '+' multiplicative_expression {$$ = new Add($1, $3);}
	| additive_expression '-' multiplicative_expression {$$ = new Subtract($1, $3);}
	;

multiplicative_expression
	: cast_expression {$$ = $1;}
	| multiplicative_expression '*' cast_expression {$$ = new Multiply($1, $3);}
	| multiplicative_expression '/' cast_expression {$$ = new Divide($1, $3);}
	| multiplicative_expression '%' cast_expression {$$ = new Modulus($1, $3);} //added
	;

cast_expression
	: unary_expression {$$ = $1;}
	| '(' type_name ')' cast_expression
	;


unary_expression
	: postfix_expression {$$ = $1;}
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression {$$ = new Unary($1, $2); }
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

postfix_expression
	: primary_expression {$$ = $1;}
	| postfix_expression '[' expression ']'  {$$ = new Array($1, $3);}
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')' {$$ = new Function_Call_With_Arguments($1, $3);}
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

primary_expression
	: IDENTIFIER {$$ = new Identifier(*$1);}
	| CONSTANT  
	| T_INT { $$ = new Int($1);}
	| STRING_LITERAL
	| '(' expression ')'
	;

parameter_type_list
	: parameter_list {$$ = new Param_List($1);} 
	;

parameter_list
	: parameter_declaration {$$ = $1;}
	| parameter_list ',' parameter_declaration {$$ = new Param_List_Declarator($1, $3);} 
	;

parameter_declaration
	: declaration_specifiers declarator {$$ = new Param_Declarator($1, $2);}
	| declaration_specifiers abstract_declarator 
	| declaration_specifiers
	;

declaration_list
	: declaration {$$ = $1;}
	| declaration_list declaration {$$ = new MultiDeclaration($1, $2);}
	;

declaration
	: declaration_specifiers ';'  {$$ = $1;}
	| declaration_specifiers init_declarator_list ';' {$$ = new MultiDec($1, $2);}
	;


argument_expression_list
	: assignment_expression {$$ = $1;}
	| argument_expression_list ',' assignment_expression {$$ = new Arg_List_Declarator($1, $3);}
	;


unary_operator
	: '&' {$$ = new UnaryOp("&");}
	| '*' {$$ = new UnaryOp("*");}
	| '+' {$$ = new UnaryOp("+");}
	| '-' {$$ = new UnaryOp("-");}
	| '~' {$$ = new UnaryOp("~");}
	| '!' {$$ = new UnaryOp("!");}
	;


assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;


constant_expression
	: conditional_expression {$$ = $1;}
	;


init_declarator_list
	: init_declarator {$$ = $1;}
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator {$$ = $1;}
	| declarator '=' initializer {$$ = new VariableAssign($1, $3);}
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;


struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier 
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;


pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


IDENTIFIER_list
	: IDENTIFIER
	| IDENTIFIER_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression {$$ = $1;}
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;


labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

selection_statement
	: IF '(' expression ')' statement  { $$ = new If($3, $5); }
	| IF '(' expression ')' statement ELSE statement { $$ = new If_Else($3, $5, $7); }
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement { $$ = new While($3, $5); }
	| DO statement WHILE '(' expression ')' ';' 
	| FOR '(' expression_statement expression_statement ')' statement 
	| FOR '(' expression_statement expression_statement expression ')' statement  { $$ = new For($3, $4, $5, $7); }
	;


%%

Base *g_root;

Base *parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");

  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }

  g_root=NULL;
  yyparse(); 
  return g_root;
}
