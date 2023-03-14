#include "ast_hpp/declarations/ast_FunctionDeclaratorWithParam.hpp"
#include "ast_hpp/declarations/ast_FunctionDefinition.hpp" 
#include "ast_hpp/declarations/ast_NameDeclarator.hpp"
#include "ast_hpp/declarations/ast_ParamDeclaration.hpp"
#include "ast_hpp/declarations/ast_ParamListDeclaration.hpp"
#include "ast_hpp/declarations/ast_ParamList.hpp"
#include "ast_hpp/declarations/ast_VariableAssign.hpp"

#include "ast_hpp/operators/ast_Add.hpp"
#include "ast_hpp/operators/ast_BitwiseAnd.hpp"
#include "ast_hpp/operators/ast_BitwiseOr.hpp"
#include "ast_hpp/operators/ast_BitwiseXor.hpp"
#include "ast_hpp/operators/ast_Divide.hpp"
#include "ast_hpp/operators/ast_Equal.hpp"
#include "ast_hpp/operators/ast_GreaterThan.hpp"
#include "ast_hpp/operators/ast_GreaterThanEqual.hpp"
#include "ast_hpp/operators/ast_LessThan.hpp"
#include "ast_hpp/operators/ast_LessThanEqual.hpp"
#include "ast_hpp/operators/ast_LogicalAnd.hpp"
#include "ast_hpp/operators/ast_LogicalOr.hpp"
#include "ast_hpp/operators/ast_Modulus.hpp"
#include "ast_hpp/operators/ast_Multiply.hpp"
#include "ast_hpp/operators/ast_NotEqual.hpp"
#include "ast_hpp/operators/ast_ShiftLeft.hpp"
#include "ast_hpp/operators/ast_ShiftRight.hpp"
#include "ast_hpp/operators/ast_Subtract.hpp"
#include "ast_hpp/operators/ast_ValueAssign.hpp"


#include "ast_hpp/multi/ast_Multiline.hpp"
#include "ast_hpp/multi/ast_MultiStatement.hpp"
#include "ast_hpp/multi/ast_MultiDeclaration.hpp"
#include "ast_hpp/multi/ast_MultiDec.hpp"

#include "ast_hpp/statements/ast_ReturnStatement.hpp"
#include "ast_hpp/statements/ast_IfElse.hpp"
#include "ast_hpp/statements/ast_If.hpp"

#include "ast_hpp/types/ast_Array.hpp"

#include "ast_hpp/ast_BaseClass.hpp"
#include "ast_hpp/ast_Identifier.hpp"
#include "ast_hpp/ast_Integer.hpp"
#include "ast_hpp/ast_Types.hpp"

#include "ast_hpp/context.hpp"


typedef std::vector<BasePtr> Vect;
typedef Vect* VectPtr;

extern Base *parseAST(std::string filename);
