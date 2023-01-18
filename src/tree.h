#ifndef __TREE_H__
#define __TREE_H__

#include <stdbool.h>

typedef enum op{ ADD, SUB, DIV, MUL } Operator;

typedef union infotype {
  int number;
  Operator op;
} Infotype;

typedef struct node *Tree;
typedef Tree Expr;

typedef struct node {
  Infotype info;
  Tree left;
  Tree right;
} Node;

bool isOneElmt(Tree tree);
bool isUnaryLeft(Tree tree);
bool isUnaryRight(Tree tree);
bool isTreeEmpty(Tree tree);

void deallocateTree(Tree tree);

Tree Number(int n);
Tree Expression(Operator op, Tree left, Tree right);

char operatorSymbol(Operator op);

int exprToStr(Expr expression, char* buffer);

void printExpression(Expr expression);

int evaluateExpression(Expr expression);

#endif