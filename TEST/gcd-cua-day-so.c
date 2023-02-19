#include <stdio.h>

void swapNum(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int lcm(int a, int b){
  if (!(a > b)) swapNum(&a, &b);
  //  a > b

  for(int i = 1; i < b; ++i){
    if (!(b % i) && !((a*i) % b)) return a*i;
  }
  
  return a * b;
}

void gcdArr(){
  int n;
  do{
    scanf("%d", &n);
  } while (n < 2 || 1000 < n);  // 2 <= n <= 1 000

  int a[n];
  int b[n+1];
  for(int i = 0; i < n; ++i){
    do{
      scanf("%d", &a[i]);
    } while (a[i] < 1 || 10000 < a[i]);  // 1 <= a[i] <= 10 000
  }

  b[0] = a[0];
  for(int i = 1; i < n; ++i){
    b[i] = lcm(a[i-1], a[i]);
  }
  b[n] = a[n-1];

  for(int i = 0; i < n+1; ++i){
    printf("%d ", b[i]);
  }
  puts("");
}

int main() {
  int cases; // number of cases
  scanf("%d", &cases);

  for(int i = 0; i < cases; ++i){
    gcdArr();
  }

  return 0;
}
