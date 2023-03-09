#include "ast_hpp/ast_BaseClass.hpp"
#include "ast_hpp/ast_FunctionDeclaratorWithParam.hpp"
#include "ast_hpp/ast_FunctionDefinition.hpp" 
#include "ast_hpp/ast_NameDeclarator.hpp"
#include "ast_hpp/ast_ParamDeclaration.hpp"
#include "ast_hpp/ast_ParamListDeclaration.hpp"
//#include "ast_hpp/ast_NodeList.hpp"
#include "ast_hpp/ast_Integer.hpp"
#include "ast_hpp/ast_ReturnStatement.hpp"
#include "ast_hpp/ast_Types.hpp"

typedef std::vector<BasePtr> Vect;
typedef Vect* VectPtr;

extern Base *parseAST(std::string filename);
