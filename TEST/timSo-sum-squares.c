#include <stdio.h>

void find(int a, int b){
  if (a > b){
    printf("%d\n", -1);  // noResult
    return;
  }

  // code something here

  printf("%d\n", -1);  // noResult
  return;
}

int main() {
  int t; // number of test cases
  int a[t];
  int b[t];
  do{
    scanf("%d", &t);
  } while (t < 1 || 100 < t);  // 1 <= t <= 100
  for(int i = 0; i < t; ++i){
    do{
      scanf("%d%d", &a[i], &b[i]);
    } while (a[i] < 1 || 10000 < a[i] || b[i] < 1 || 10000 < b[i]);  // 1 <= a[i], b[i] <= 10 000
  }

  for(int i = 0; i < t; ++i){
    find(a[i], b[i]);
  }

  return 0;
}