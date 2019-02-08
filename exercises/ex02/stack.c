/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

// 1) This code wants to return the address of an array, defined in foo, and then defined in bar.
// In main, it wants to print the elements in the array.

// 2) When compiled, I get: warning: function returns address of local variable for 'return array'
// Since array was created inside the function, it can't be accessed in a different stack frame,
// once that function is done running.

// 3) I get the error: Segmentation fault (core dumped).
// This is because array[] was created in foo(), and foo() is trying to pass it to main.
// Foo goes away once it's done running, so main has no way to access array[].

// 4) Even with print statements commented, code doesn't Compile
// If code did compile, it would just print the address of the array


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
