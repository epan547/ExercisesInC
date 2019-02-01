#include <stdio.h>

int main() {
    int x = 5; // with flag -o2, code still acts normal
    int y = x + 1;

    printf("%d\n", y);
    return 0;
}


/*
  2) code executed as normal with -o2 flag
  3) printing x works as expected with and without optimization.
  However, the assembly code is shorter, so it probabaly has a shorter run time
  4) printing y works as expected with and without optimization.
  However, the assembly code is shorter, so it probably has a shorter run time.
*/
