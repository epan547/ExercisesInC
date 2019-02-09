#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int flag = 0;
int array[11];
int count = 0;

int scan_input() {
  static char number[10];
  puts("Enter an integer: ");
  char* f = fgets(number, 10, stdin);

  //  IF user inputs ^D, end the loop
  if (number[0] == EOF || f == NULL) {
    flag = 1;
    return -1;
  }

  // If the user input is too long, loop again
  if (strlen(number) == 9) {
    printf("That's too long. Try again\n");
    memset(number, 0, 10);
    return 0;
  }

  // if atoi(number) == 0, the input is not a number
  if (atoi(number) != 0) {
    return atoi(number);
  }
  else {
    printf("Not a number. Try again\n");
  }
  return 0;
}



int main()
{
  while(flag==0){

    // Scan input number and add to array if ^D is not true
    int num = scan_input();
    if (num == -1){
      break;
    }
    if (count >= 10){
      printf("Your array is full.\n");
      break;
    }
    array[count] = num;
    count ++;
  }

  // When loop is broken, sum up numbers, and print them
  int sum = 0;
  for(int i=0; i<10; i++) {
    sum += array[i];
  }

  printf("The sum is: %i\n", sum );

  return 0;
}
