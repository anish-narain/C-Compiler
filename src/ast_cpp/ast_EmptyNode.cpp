#include "ast_hpp/ast_EmptyNode.hpp"

// Constructor
EmptyNode::EmptyNode()
{}

//Destructor
EmptyNode::~EmptyNode()
{}

// Visualising
void EmptyNode::print(std::ostream &dst, std::string indent) const
{
  dst << "reached" << std::endl;
}

void EmptyNode::RISCOutput(std::ostream &dst, context &context, int destReg) const
{}

int EmptyNode::getSize() const{
  return 0;
}

void EmptyNode::isFunctionCall(context &context) const{
  //std::cerr << "EmptyNodeFunctionCall" << std::endl;
}

void EmptyNode::isPointer(context &context) const{

}
