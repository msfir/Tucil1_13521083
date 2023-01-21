#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "solver.h"

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

void generate_cards(char cards[4][4], int cards_int[4]) {
  time_t t;
  srand((unsigned) time(&t));
  for (int i = 0; i < 4; i++) {
    int idx = rand() % CARDS_LENGTH;
    sprintf(cards[i], "%s", CARDS[idx]);
    cards_int[i] = idx + 1;
  }
}

void get_user_input(char cards[4][4], int cards_int[4]) {

}

int main_menu() {
  int choice;
  do {
    puts("Pilih opsi berikut ini");
    puts("[1] Masukkan kartu secara manual");
    puts("[2] Bangkitkan kartu secara acak");
    puts("[3] Keluar");
    puts("");
    printf("Masukan: ");
    scanf("%d", &choice);
  } while (choice < 1 || choice > 3);
  return choice;
}

int main() {
  char cards[4][4];
  int cards_int[4];
  char solutions[500][22];
  puts("------------------------------");
  puts("|     24 Card Game Solver    |");
  puts("------------------------------");
  int choice = main_menu();
  puts("");
  switch (choice) {
    case 1:
      get_user_input(cards, cards_int);
      break;
    case 2:
      generate_cards(cards, cards_int);
      break;
    default:
      puts("Bye.");
      exit(0);
  }
  printf("Kartu: %s %s %s %s\n", cards[0], cards[1], cards[2], cards[3]);
  int n = make24(cards_int[0], cards_int[1], cards_int[2], cards_int[3], solutions);
  printf("Ditemukan %d solusi:\n", n);
  for (int i = 0; i < n; i++) {
    printf("%2d. %s\n", i + 1, solutions[i]);
  }
  return 0;
}