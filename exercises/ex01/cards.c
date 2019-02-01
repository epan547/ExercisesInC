/*
* Program to evaluate face values.
* Released under the Vegas Public License.
* (c)2014 The College Blackjack Team.
*/

/*
  With the: gcc -ansi -pedantic -Wall cards.c
  flag, I got additional warnings for commented code.
  Since I no longer needed it, I deleted it.
  It warns about words too, so I don't think it was the code.
  Now it compiles cleanly!
*/

#include <stdio.h>
#include <stdlib.h>

/* Scans user input and stores result in card_name

      prompt: string "Enter the card_name: " to display
      card_name: buffer where result is stored (2 chars max)
*/

char * scan_card() {
  static char card_name[3];
  puts("Enter the card_name: ");
  scanf("%2s",card_name);
  return card_name;
}

/* Assigns the given character card_name a blackjack value,
according to rules of the game.

Inputs:
    card_name: buffer where user input is stored (2 chars max)
    v: integer equivalent of input card_name

Output:
    val: integer blackjack value of card

*/

int check_val(char * card_name, int v) {
  int val = 0;
  if (card_name[0] == 'K') {
    val = 10;
  } else if (card_name[0] == 'Q') {
    val = 10;
  } else if (card_name[0] == 'J') {
    val = 10;
  } else if (card_name[0] == 'A') {
    val = 11;
  } else {
    val = v;
  }
  return val;
}

/* Prompts the user for input and puts the reply as a value
   in the given buffer. User input is truncated to the first two characters.

   card_name: buffer where result is stored
   v: first character of card_name
   new_val: blackjack value of the card
*/
int main() {
  char * card_name = scan_card();

  int v = atoi(card_name);
  int new_val = check_val(card_name, v);

  printf("The card value is: %i\n", new_val);
  return 0;
}
