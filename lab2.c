#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  printf("Enter a program to run.\n");
  while (1) {

    read = getline(&line, &len, stdin);

    if (read == -1) {
      break;
    }

    pid_t pid = fork();
    if (pid < 0) {
      perror("Fork");
      continue;
    }

    if (pid == 0) {
      // learn excel
      // call excel
      execl(line, line, (char *)NULL);
      perror("Exct failure");
      exit(EXIT_FAILURE);
    } else {
      waitpid(pid, NULL, 0);
    }
  }

  return 0;
}
