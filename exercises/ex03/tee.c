/* This is a rudimentary C implementation of the tee terminal command, linked here: http://man7.org/linux/man-pages/man1/tee.1.html

The program reads user input, assuming the first argument is "tee", and then
echoes user input, writing it to a filename, specified in the last argument.

If the -a flag is given, then the user input will be appended to the file,
instead of re-writing it, if it already exists (default).

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 80


int main(int argc, char*argv[]){
  char ch;
  char* filename;

// Check for filename after tee command
  if(argc > 1){
    filename = argv[argc-1];
    // printf("%s\n", filename);
  }
  else{
    // Not an input, return
    fprintf(stderr, "No filename");
    return 0;
  }

// Flags for ways to change input
  int a = 0;
  int p = 0;
  int i = 0;

// Respond based on argument received
  while((ch = getopt(argc, argv, "tee: a p i")) != EOF) {
    switch(ch){
      case 'p':
        p = 1;
        break;
      case 'a':
        a = 1;
        break;
      case 'i':
        i = 1;
        break;
      default:
        return 1;
    }
  }

// Creating a file for writing
FILE* file1;
  if(a == 1){
    file1 = fopen(filename, "a");
  }
  else {
    file1 = fopen(filename, "w");
  }


  // Echoing the user input
  char buff[MAX];
  while(fgets(buff, MAX, stdin) != NULL){
    printf("%s", buff);
    fprintf(file1, "%s", buff);
  }

  fclose(file1);

  return 0;
}
