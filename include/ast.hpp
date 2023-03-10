#include "ast_hpp/ast_BaseClass.hpp"
#include "ast_hpp/ast_FunctionDeclaratorWithParam.hpp"
#include "ast_hpp/ast_FunctionDefinition.hpp" 
#include "ast_hpp/ast_Integer.hpp"
#include "ast_hpp/ast_NameDeclarator.hpp"
#include "ast_hpp/ast_ParamDeclaration.hpp"
#include "ast_hpp/ast_ParamListDeclaration.hpp"
#include "ast_hpp/ast_ReturnStatement.hpp"
#include "ast_hpp/ast_Types.hpp"


#include "ast_hpp/ast_Add.hpp"
#include "ast_hpp/ast_Divide.hpp"
#include "ast_hpp/ast_Multiply.hpp"
#include "ast_hpp/ast_Subtract.hpp"
#include "ast_hpp/ast_BitwiseAnd.hpp"
#include "ast_hpp/ast_BitwiseOr.hpp"
#include "ast_hpp/ast_BitwiseXor.hpp"
#include "ast_hpp/ast_Equal.hpp"
#include "ast_hpp/ast_LessThan.hpp"
#include "ast_hpp/ast_LessThanEqual.hpp"
#include "ast_hpp/ast_LogicalAnd.hpp"
#include "ast_hpp/ast_LogicalOr.hpp"
#include "ast_hpp/ast_GreaterThan.hpp"
#include "ast_hpp/ast_GreaterThanEqual.hpp"

#include "ast_hpp/ast_Identifier.hpp"

//#include "ast_hpp/operators/"

typedef std::vector<BasePtr> Vect;
typedef Vect* VectPtr;

extern Base *parseAST(std::string filename);
