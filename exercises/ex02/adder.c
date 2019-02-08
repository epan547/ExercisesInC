#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int flag = 0;
int array[11];
int count = 0;

int scan_card() {
  static char number[100];
  puts("Enter an integer: ");
  int f = scanf("%2s",number);

  if (number[0] == EOF || f < 0) {
    flag = 1;
    return -1;
  }
  if (strlen(number) >= 99) {
    printf("That's too long. Try again");
    return 0;
  }
  if (atoi(number) != 0) {
    return atoi(number);
  }
  return 0;
}



int main()
{
  while(flag==0){
    int num = scan_card();
    if (num == -1){
      break;
    }
    array[count] = num;
    count ++;
  }
  int sum = 0;
  for(int i=0; i<10; i++) {
    sum += array[i];
  }

  printf("The sum is: %i\n", sum );

  return 0;
}
