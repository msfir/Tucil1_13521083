#ifndef SOLVER_H_
#define SOLVER_H_

typedef enum { ADD, SUB, DIV, MUL } Operator;

char operatorSymbol(Operator op);

float eval(Operator op, float left, float right);

bool arrays_equal(const int* a, const int* b, const int size);

int str_length(const char* s);

void copy_array(const int* source, int* destination, int size);

bool is_element4(int e[4], int arr[24][4], int size);

int unique_permutations4(int arr[4], int buffer[][4]);

int make24(int a, int b, int c, int d, char solutions[][22]);

#endif