#include <stdbool.h>
#include <stdio.h>

#define Number(n) &(Node) { .info=n }
#define Expression(op, l, r) &(Node) { .info=op, .left=l, .right=r }

typedef enum operator{ ADD, SUB, DIV, MUL } Operator;

typedef union infotype {
  int number;
  Operator operator;
} Infotype;

typedef struct node *Tree;
typedef Tree Expr;

typedef struct node {
  Infotype info;
  Tree left;
  Tree right;
} Node;

bool isOneElmt(Tree tree) {
  return tree->left == NULL && tree->right == NULL;
}

bool isUnaryLeft(Tree tree) {
  return tree->left != NULL && tree->right == NULL;
}

bool isUnaryRight(Tree tree) {
  return tree->left == NULL && tree->right != NULL;
}

bool isTreeEmpty(Tree tree) { return tree == NULL; }

void printOperator(Operator op) {
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
  printf("%c", sym);
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
    printOperator(expression->info.operator);
    __printExpression(expression->right, height + 1);

    if (height > 0) {
      printf(")");
    }
  }
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
    Operator op = expression->info.operator;
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

int main() {
  Expr expr = Expression(
    DIV,
    Expression(
      MUL,
      Number(12),
      Expression(
        ADD,
        Number(3),
        Expression(
          SUB,
          Number(13),
          Number(7)))),
    Number(3));
  printExpression(expr);
  printf(" = %d\n", evaluateExpression(expr));
  return 0;
}