#include <stdio.h>

int main() {
    int x = 5; // with flag -o2, code still acts normal
    int y = x + 1;

    test_addp();
    printf("%d\n", y);
    return 0;
}

void addp(int* p1, int* p2, int* p3) {
  *p3 = *p1 + *p2;
}

void test_addp() {
  int a = 3;
  int b = 4;
  int c;
  int* a1 = &a;
  // a1 = &a;
  // b1 = &b;
  // c1 = &c;
  // addp(a1,b1,c1);
  printf("%d\n", c);
}

/*
  2) code executed as normal with -o2 flag
  3) printing x works as expected with and without optimization.
  However, the assembly code is shorter, so it probabaly has a shorter run time
  4) printing y works as expected with and without optimization.
  However, the assembly code is shorter, so it probably has a shorter run time.
*/
