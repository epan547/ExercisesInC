#include <stdio.h>
#include "minunit.h"
#include "util.h"

int tests_run = 0;

int foo = 7;
int bar = 4;

static char * test_foo() {
    mu_assert("error, foo != 7", foo == 7);
    return 0;
}

static char * test_bar() {
    mu_assert("error, bar != 5", bar == 5);
    return 0;
}

static char * test1() {
  int code = 0;
  char* icmpcode = icmpcode_v4(code);
  // printf("%s\n",icmpcode);
  int check = strcmp(icmpcode, "network unreachable");
  mu_assert("error, wrong message", check == 0);

  return NULL;
}

static char * test2() {
  int code = 1;
  char* icmcode = icmpcode_v4(code);
  int check = strcmp(icmcode, "host unreachable");
  // printf("%s\n",icmcode);
  mu_assert("error, wrong message", check == 0);

  return NULL;
}


static char * all_tests() {
    // mu_run_test(test_foo);
    // mu_run_test(test_bar);
    mu_run_test(test1);
    mu_run_test(test2);
    return 0;
}


int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
