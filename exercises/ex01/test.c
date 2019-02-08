/* addp: add the pointees of p1 and p2,and store the result in the pointee of p3. */
#include <stdio.h>


void addp(int* p1, int* p2, int* p3) {
// This function was missing the *p3
  *p3 = *p1 + *p2;
}


/* test_addp: test addp and print the result */
void test_addp() {
  // Test addp is correct
  int a = 3;
  int b = 4;
  int c;
  addp(&a, &b, &c);
  printf("%d\n", c);
}

char* check_parity(int n) {
  // missing breaks
  // missing char* return type
  switch (n%2) {
    case 0: {
      char* msg = "n is even";
      return msg;
      break;
    }
    case 1: {
      char* msg = "n is odd";
      return msg;
      break;
    }
  }
}

void main() {
  // missing n declaration
  int n = 7;
  test_addp();
  char *s = check_parity(n);
  printf("%s\n", s);
}
