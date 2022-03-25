#include <stdio.h>
#include <math.h>

unsigned int lengNum(unsigned long long num){
  return floor(log10(num)) + 1;
}

void handing(unsigned long long *num, int *mod){
  *mod = *num % 10;  // get last number
  *num = *num / 10;  // del last number
}

int cutNum(int num){
  if (num % 8 > 1) return 2;  //  cut INVALID

  // remaining 0 1 8 9
  if (num == 1) return 1;  // 1 cut into 1
  return 0;  // 0 8 9  cut into 0
}

void cut(unsigned long long num){
  unsigned long long res = 0;
  int mod;
  unsigned long long end = 1;
  while(num > 0){
    handing(&num, &mod);
    mod = cutNum(mod);
    if (mod == 2){
      printf("INVALID\n");
      return;
    }
    res = mod * end + res;  // add mod to left
    end *= 10;
  }
  if (res == 0){
    printf("INVALID\n");
    return;
  }
  printf("%llu\n", res);
}

int main(){
  unsigned int n;
  scanf("%d", &n);
  unsigned long long num[n];
  for(int i = 0; i < n; i++){
    do{
      scanf("%llu", &num[i]);
    } while (lengNum(num[i]) > 18);
  }
  for(int i = 0; i < n; i++){
    cut(num[i]);
  }
  return 0;
}
