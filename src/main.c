#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_BUFFER 4
#define CARDS_LENGTH 13

bool parse_input(const char* input, int* output) {
  int val;
  int n = sscanf(input, "%d", &val);
  if (n != 1) {
    char c;
    sscanf(input, "%c", &c);
    switch (c) {
      case 'A':
        *output = 1;
        return true;
      case 'J':
        *output = 11;
        return true;
      case 'Q':
        *output = 12;
        return true;
      case 'K':
        *output = 13;
        return true;
      default:
        return false;
    }
  }
  if (2 <= val && val <= 10) {
    *output = val;
    return true;
  }
  return false;
}

static const const char* CARDS[CARDS_LENGTH] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

void generate_cards(char cards[4][4]) {
  time_t t;
  srand((unsigned) time(&t));
  for (int i = 0; i < 4; i++) {
    int idx = rand() % CARDS_LENGTH;
    sprintf(cards[i], "%s", CARDS[idx]);
  }
}

int main() {
  char cards[4][4];
  generate_cards(cards);
  for (int i = 0; i < 4; i++) {
    printf("%s\n", cards[i]);
  }
  return 0;
}