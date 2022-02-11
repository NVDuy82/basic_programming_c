#include <stdio.h>
#include <math.h>

char check(int n){
  if(n < 2) return 0;
  if(n == 2) return 1;
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
