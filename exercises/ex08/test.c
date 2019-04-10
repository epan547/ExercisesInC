
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num, den;
} Rational;

Rational *make_rat(int num, int den) {
    Rational *rat = malloc(sizeof(Rational));
    rat->num = num;
    rat->den = den;
    return rat;
}

int compare_rationals(const void* point_a, const void* point_b) {
  Rational* a = *(Rational**) point_a;
  Rational* b = *(Rational**) point_b;

  float fa = a->num/a->den;
  float fb = b->num/b->den;
  return (int) fb-fa; //a-b is ascending, b-a is descending
}

void sort_rationals(Rational** array, int n){
  qsort(array, n, sizeof(int), compare_rationals);
}

void print_rational(Rational** array, int n) {
    for (int j=0; j<n; j++) {
        printf("%f / %f \n", array[j]->num, array[j]->den);
    }
}

int main(){
  Rational array[] = malloc(sizeof(Rational)*5);
  Rational *rat = make_rat(3, 4);
  array.add(rat);
  for (int i=1; i<4; i++) {
      Rational *rat = make_rat(i, 6);
      array.add(rat);
  }
  print_rational(array, 5);
  sort_rationals(array, 5);
  print_rational(array,5);
}
