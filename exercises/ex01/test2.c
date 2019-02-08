/* addp: add the pointees of p1 and p2,and store the result in the pointee of p3. */
#include <stdio.h>
#include <stdlib.h>


int card_value(char *card_name) {
  switch(card_name[0]) {
    case 'K': case 'Q': case 'J':
      return 10;
    case 'A':
      return 11;
    default: {
      int val = atoi(card_name);
      if ((val>=1)&&(val<=10)) {
        return val;
      }
    }
  }
  return -1;
}

void main() {
  // missing n declaration
  char* name = 'A';
  int i = card_value(name);
}
