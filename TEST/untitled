#include <stdio.h>
#define C 64

int min(int a, int b){
  return a < b ? a : b;  
}

int main() {
  int start, max;  
  scanf("%d%d", &start, &max);
  while(start > 0){
    int count = 0;
    for(int i = start; i < max; i++){
      printf("%c", C + i);
      count++;
    }
    while(count < max){
      printf("%c", C + max);
      count++;
    }
    printf("\n");
    start--;
  }
  return 0;
}
