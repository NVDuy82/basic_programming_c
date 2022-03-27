#include <stdio.h>
#include<math.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void swapHcn(int *hcn1, int *hcn2){
  for(int i = o; i <= 1; i++){
    swap(hcn1 + i, hcn2 + i);
  }
}

void sort(int *hcn){
  // sort A -> Z
  if (hcn[0] > hcn[1]) swap(&hcn[0], &hcn[1]);
}

int main() {
  int hcn[3][2];
  int s = 0;

  // input
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      scanf("%d", &hcn[i][j]);
    }
    s += hcn[i][0] * hcn[i][1];
    sort(hcn[i]);
  }

  // output
  int edge = sqrt(s);
  if (edge == sqrt(s)){    
    if (hcn[0][1] == hcn[1][1] && hcn[1][1] == hcn[2][1] && hcn[2][1] == edge){
      // cac canh lon cua hinh vuong = edge
      printf("YES");
      return 0;
    } else {
      for(int i = 1; i < 3; i++){
        if (hcn[i][1] == edge){
          swapHcn(hcn[0], hcn[i]); // di chuyen hcn co canh = edge len hcn[0]
        }
      }
      if (hcn[0][1] == edge){
        // 2 hcn con lai co canh = edge - hcn[0][0] 
        hcn[0][0] = edge - hcn[0][0];
        for(int i = 0; i < 2; i++){
          for(int j = 0; j < 2; j++){
            if(hcn[1][i] == hcn[2][j] && hcn[2][j] == hcn[0][0]){
              printf("YES");
              return 0;
            }
          }
        }
      }
    }
  }
  printf("NO");
  return 0;
}