/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_address() {
  int x = 5;
  printf("Address of local var x is %p\n", &x);
}

int main ()
{
    int var2 = 5;
    void *k = malloc(16);
    void *p = malloc(16);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("k points to %p\n", k);
    print_address();

    return 0;
}
