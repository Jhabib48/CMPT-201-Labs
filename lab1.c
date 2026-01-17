#define _POSIX_C_SOURCE 200809L
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int exit = 0;
  char *token;
  char *saveptr;

  while (exit != -1) {
    printf("Please enter some text or CRT-D to exit: ");

    read = getline(&line, &len, stdin);
    if (read == 1)
      continue;
    if (read == -1)
      break;

    token = strtok_r(line, " ", &saveptr);
    printf("Token:");
    while (token != NULL) {
      printf("\n\t%s", token);
      token = strtok_r(NULL, " ", &saveptr);
    }
  }

  free(line);
  return 0;
}
