#include "tree.h"
#include <stdio.h>

int main() {
  Expr expr = Expression(
    MUL,
    Number(10),
    Expression(
      ADD,
      Expression(
        SUB,
        Number(6),
        Number(3)),
      Expression(
        DIV,
        Number(12),
        Number(3))));
  printExpression(expr);
  printf(" = %d\n", evaluateExpression(expr));
  char str[64];
  exprToStr(expr, str);
  printf("%s\n", str);
  deallocateTree(expr);
  return 0;
}