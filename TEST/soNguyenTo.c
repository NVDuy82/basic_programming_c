#include <stdio.h>
#include <math.h>

char check(unsigned n){
  if(n < 2) return 0;  // 0 1 not prime number
  if(n == 2) return 1;  // 2 is prime number
  if(!(n % 2)) return 0; // even num > 2 -> not prime number
  // for remaining num -> (3 5 7 9 ....)
  // check odd divisor
  for(int i = 3; i <= round(sqrt(n)); i += 2){
    if(!(n % i)) return 0;
  }
  return 1;
}

int main() {
  unsigned int l;
    scanf("%d", &l);

  unsigned int n[l];
  for(int i = 0; i < l; i++){
    scanf("%d", &n[i]);
  }

  for(int i = 0; i < l; i++){
    if(check(n[i]))
      printf("YES");
    else
      printf("NO");
    printf("\n");
  }  
  return 0;
}
