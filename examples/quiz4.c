#include <stdio.h>
#include <stdlib.h>


union {
  float f;
  u_int32_t i;
} b;

u_int32_t get_exponent(float x) {
  b.f = x;
  u_int32_t mask = 0xff;
  u_int32_t expon = (b.i >> 23) & mask;
  return expon;
}

float div_by_pow_2(float x, int n){
  // First exponent, second is int n
  u_int32_t u = get_exponent(x);
  u_int32_t y = u-n;
  b.f = x;
  u_int32_t z = b.i << 8; // (y << 23) | b.i;
  u_int32_t a = b.i >> 8;
  printf("%i\n", y);
  printf("%d\n", z);
  printf("%d\n", a);

}

int main(){
  float x = 15;
  int n = 2;

  u_int32_t u = get_exponent(x);
  float ans = div_by_pow_2(x, n);
  // printf("%d\n",u);
  // printf("%f \n", ans);
}
