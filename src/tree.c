#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

bool isOneElmt(Tree tree) {
  return tree->left == NULL && tree->right == NULL;
}

bool isUnaryLeft(Tree tree) {
  return tree->left != NULL && tree->right == NULL;
}

bool isUnaryRight(Tree tree) {
  return tree->left == NULL && tree->right != NULL;
}

bool isTreeEmpty(Tree tree) {
  return tree == NULL;
}

void deallocateTree(Tree tree) {
  if (isTreeEmpty(tree)) {
    return;
  }
  deallocateTree(tree->left);
  deallocateTree(tree->right);
  free(tree);
}

Tree Number(int n) {
  Tree node = (Tree) malloc(sizeof(Node));
  node->info = (Infotype) n;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Tree Expression(Operator op, Tree left, Tree right) {
  Tree node = (Tree) malloc(sizeof(Node));
  node->info = (Infotype) op;
  node->left = left;
  node->right = right;
  return node;
}

char operatorSymbol(Operator op) {
  char sym = '?';
  if (op == ADD) {
    sym = '+';
  } else if (op == SUB) {
    sym = '-';
  } else if (op == MUL) {
    sym = '*';
  } else if (op == DIV) {
    sym = '/';
  }
  return sym;
}

void __printExpression(Expr expression, int height) {
  if (isTreeEmpty(expression)) {
    return;
  } else if (isOneElmt(expression)) {
    printf("%d", expression->info.number);
  } else {
    if (height > 0) {
      printf("(");
    }

    __printExpression(expression->left, height + 1);
    printf("%c", operatorSymbol(expression->info.op));
    __printExpression(expression->right, height + 1);

    if (height > 0) {
      printf(")");
    }
  }
}

int __exprToStr(Expr expression, int height, char* buffer, int offset) {
  if (isTreeEmpty(expression)) {
    return offset;
  } else if (isOneElmt(expression)) {
    return offset + sprintf(buffer + offset, "%d", expression->info.number);
  } else {
    if (height > 0) {
      offset += sprintf(buffer + offset, "(");
    }

    offset = __exprToStr(expression->left, height + 1, buffer, offset);
    offset += sprintf(buffer + offset, "%c", operatorSymbol(expression->info.op));
    offset = __exprToStr(expression->right, height + 1, buffer, offset);

    if (height > 0) {
      offset += sprintf(buffer + offset, ")");
    }
    return offset;
  }
}

int exprToStr(Expr expression, char* buffer) {
  return __exprToStr(expression, 0, buffer, 0);
}

void printExpression(Expr expression) {
  __printExpression(expression, 0);
}

int evaluateExpression(Expr expression) {
  if (isTreeEmpty(expression)) {
    return 0;
  } else if (isOneElmt(expression)) {
    return expression->info.number;
  } else {
    Operator op = expression->info.op;
    int left = evaluateExpression(expression->left);
    int right = evaluateExpression(expression->right);
    int value = 0;
    if (op == ADD) {
      value = left + right;
    } else if (op == SUB) {
      value = left - right;
    } else if (op == MUL) {
      value = left * right;
    } else if (op == DIV) {
      value = left / right;
    }
    return value;
  }
}