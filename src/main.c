#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "solver.h"

#define MAX_INPUT_BUFFER 20
#define CARDS_LENGTH 13
#define MAX_FILE_NAME_LENGTH 100

static const const char* CARDS[CARDS_LENGTH] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

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

void save_solutions(const char* file_name, const char cards[4][MAX_INPUT_BUFFER], const char solutions[][22], const int num_of_solutions) {
  FILE* file;
  file = fopen(file_name, "w");
  if (errno) {
    perror("Gagal menyimpan solusi");
    exit(1);
  }
  fprintf(file, "Kartu: %s %s %s %s\n", cards[0], cards[1], cards[2], cards[3]);
  fprintf(file, "Solusi:");
  for (int i = 0; i < num_of_solutions; i++) {
    fprintf(file, "\n%d. %s", i + 1, solutions[i]);
  }
  fclose(file);
}

void generate_cards(char cards[4][MAX_INPUT_BUFFER], int cards_int[4]) {
  time_t t;
  srand(time(&t));
  for (int i = 0; i < 4; i++) {
    int idx = rand() % CARDS_LENGTH;
    sprintf(cards[i], "%s", CARDS[idx]);
    cards_int[i] = idx + 1;
  }
}

void clear_stdin() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void get_user_input(char cards[4][MAX_INPUT_BUFFER], int cards_int[4]) {
  bool valid;
  do {
    valid = true;
    printf("Masukkan kartu: ");
    scanf("%s %s %s %s", cards[0], cards[1], cards[2], cards[3]);
    for (int i = 0; i < 4 && valid; i++) {
      if (!parse_input(cards[i], &cards_int[i])) {
        valid = false;
      }
    }
    if (!valid) {
      puts("Masukan tidak valid");
    }
    clear_stdin();
  } while (!valid);
}

int main_menu() {
  int choice;
  bool valid = false;
  do {
    puts("");
    puts("Pilih opsi berikut ini");
    puts("[1] Masukkan kartu secara manual");
    puts("[2] Bangkitkan kartu secara acak");
    puts("");
    printf("Masukan: ");
    scanf("%d", &choice);
    valid = choice == 1 || choice == 2;
    if (!valid) {
      puts("Masukan tidak sesuai");
    }
  } while (!valid);
  clear_stdin();
  return choice;
}

int main() {
  char cards[4][MAX_INPUT_BUFFER];
  int cards_int[4];
  char solutions[500][22];
  clock_t elapsed_time;
  puts("------------------------------");
  puts("|     24 Card Game Solver    |");
  puts("------------------------------");
  int choice = main_menu();
  puts("");
  switch (choice) {
    case 1:
      get_user_input(cards, cards_int);
      puts("");
      break;
    case 2:
      generate_cards(cards, cards_int);
      break;
    default:
      // unreachable
      exit(1);
  }
  printf("Kartu: %s %s %s %s\n", cards[0], cards[1], cards[2], cards[3]);
  elapsed_time = clock();
  int n = make24(cards_int[0], cards_int[1], cards_int[2], cards_int[3], solutions);
  elapsed_time = clock() - elapsed_time;
  if (n > 0) {
    printf("Ditemukan %d solusi:\n", n);
    for (int i = 0; i < n; i++) {
      printf("%d. %s\n", i + 1, solutions[i]);
    }
    printf("Kartu: %s %s %s %s\n", cards[0], cards[1], cards[2], cards[3]);
    int n = make24(cards_int[0], cards_int[1], cards_int[2], cards_int[3], solutions);
    if (n > 0) {
      printf("Ditemukan %d solusi:\n", n);
      for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, solutions[i]);
      }
      char ans[MAX_INPUT_BUFFER];
      do {
        printf("Apakah Anda ingin menyimpan solusi? (y/[n]) ");
        fgets(ans, MAX_INPUT_BUFFER, stdin);
      } while (ans[0] != 'y' && ans[0] != 'n' && ans[0] != '\n');
      if (ans[0] == 'y') {
        char file_name[MAX_FILE_NAME_LENGTH];
        printf("Masukkan nama file: ");
        fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);
        int len = str_length(file_name);
        if (len > 0 && file_name[len - 1] == '\n') {
          file_name[--len] = '\0';
        }
        save_solutions(file_name, cards, solutions, n);
      }
    } else {
      puts("Tidak ditemukan solusi");
    }
  } else {
    puts("Tidak ada solusi");
  }
  printf("Waktu eksekusi program: %.3lf ms\n", (double) elapsed_time / CLOCKS_PER_SEC * 1000);
}