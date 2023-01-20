#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum operator{ ADD, SUB, DIV, MUL } Operator;

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

float eval(Operator op, float left, float right) {
  switch (op) {
    case ADD: return left + right;
    case SUB: return left - right;
    case MUL: return left * right;
    case DIV: return left / right;
    default: return 0;
  }
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

bool arrays_equal(const int* a, const int* b, const int size) {
  int i = 0;
  while (i < size) {
    if (a[i] != b[i]) {
      return false;
    }
    i++;
  }
  return true;
}

void copy_array(const int* source, int* destination, int size) {
  for (int i = 0; i < size; i++) {
    destination[i] = source[i];
  }
}

int cmp_int(const void* a, const void* b) {
  return *(int*) a - *(int*) b;
}

bool is_element4(int e[4], int arr[24][4], int size) {
  int i = 0;
  while (i < size) {
    if (arrays_equal(e, arr[i], 4)) {
      return true;
    }
    i++;
  }
  return false;
}

int unique_permutations4(int arr[4], int buffer[][4]) {
  qsort(arr, 4, sizeof(int), cmp_int);
  int len = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
          int temp[4];
          temp[0] = arr[i];
          if (i != j) {
            temp[1] = arr[j];
            if (i != k && j != k) {
              temp[2] = arr[k];
              if (i != l && j != l && k != l) {
                temp[3] = arr[l];
                if (len == 0 || !is_element4(temp, buffer, len)) {
                  copy_array(temp, buffer[len++], 4);
                }
              }
            }
          }
        }
      }
    }
  }
  return len;
}

int make24(int a, int b, int c, int d, char solutions[][22]) {
  int n = 0;
  int buffer[24][4];
  int arr[4] = {a, b, c, d};
  int p = unique_permutations4(arr, buffer);

  // menghindari solusi yang komutatif
  char banned[64][22];
  int banned_len = 0;
  for (int i = 0; i < p; i++) {
    a = buffer[i][0];
    b = buffer[i][1];
    c = buffer[i][2];
    d = buffer[i][3];
    for (Operator op1 = ADD; op1 <= MUL; op1++) {
      char opc1 = operatorSymbol(op1);
      for (Operator op2 = ADD; op2 <= MUL; op2++) {
        char opc2 = operatorSymbol(op2);
        for (Operator op3 = ADD; op3 <= MUL; op3++) {
          char opc3 = operatorSymbol(op3);
          // hardcode 5 kemungkinan urutan evaluasi
          // case 1: ((a + b) + c) + d
          if (eval(op3, eval(op2, eval(op1, a, b), c), d) == 24) {
            sprintf(solutions[n++], "(%d %c %d) %c %d) %c %d", a, opc1, b, opc2, c, opc3, d);
          }
          // case 2: (a + (b + c)) + d
          if (eval(op3, eval(op1, a, eval(op2, b, c)), d) == 24) {
            sprintf(solutions[n++], "(%d %c (%d %c %d)) %c %d", a, opc1, b, opc2, c, opc3, d);
          }
          // case 3: (a + b) + (c + d)
          if (eval(op2, eval(op1, a, b), eval(op3, c, d)) == 24) {
            sprintf(solutions[n++], "(%d %c %d) %c (%d %c %d)", a, opc1, b, opc2, c, opc3, d);
          }
          // case 4: a + ((b + c) + d)
          if (eval(op1, a, eval(op3, eval(op2, b, c), d)) == 24) {
            sprintf(solutions[n++], "%d %c ((%d %c %d) %c %d)", a, opc1, b, opc2, c, opc3, d);
          }
          // case 5: a + (b + (c + d))
          if (eval(op1, a, eval(op2, b, eval(op3, c, d))) == 24) {
            sprintf(solutions[n++], "%d %c (%d %c (%d %c %d))", a, opc1, b, opc2, c, opc3, d);
          }
        }
      }
    }
  }
  return n;
}

int main() {
  char solutions[320][22];
  int n = make24(1, 2, 3, 4, solutions);
  printf("Banyak solusi: %d\n", n);
  for (int i = 0; i < n; i++) {
    printf("%2d. %s\n", i + 1, solutions[i]);
  }
  return 0;
}