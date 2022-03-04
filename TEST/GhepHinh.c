#include <stdio.h>
#include<math.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int *hcn){
  if (hcn[0] > hcn[1]) swap(&hcn[0], &hcn[1]);
}

int main() {
  int hcn[3][2];
  int s = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      scanf("%d", &hcn[i][j]);
    }
    s += hcn[i][0] * hcn[i][1];
    sort(hcn[i]);
  }
  int edge = sqrt(s);
  if (edge == sqrt(s)){    
    if (hcn[0][1] == hcn[1][1] && hcn[1][1] == hcn[2][1] && hcn[2][1] == edge){
      printf("YES");
      return 0;
    } else {      
      for(int i = 1; i < 3; i++){
        if (hcn[i][1] == edge){
          for(int j = 0; j < 2; j++){
            swap(&hcn[0][j], &hcn[i][j]);
          }
        }        
      }
      if (hcn[0][1] == edge){        
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
