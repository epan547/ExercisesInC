

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>

int main() {
  int status;
  for (int i=0; i<2; i++) {
    printf("a\n");
    pid_t pid = fork();
    if (pid == 0) {
      printf("%d\n", i);
      // exit(i);
    }
  }
  printf("b\n");
  for (int i=0; i<2; i++) {
    pid_t pid = wait(&status);
    printf("c\n");
  }
}
