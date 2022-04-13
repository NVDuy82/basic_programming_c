#include <stdio.h>

void swap_0_1(int *a){
  *a = 1 - *a;
}

int main() {
  int n;
  do{
    scanf("%d", &n);
  } while(n < 1 || 10 < n);
  int arr[n][n];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      do{
        scanf("%d", &arr[i][j]);
      } while(arr[i][j] != 0 && arr[i][j] != 1);
    }
  }
  printf("n = %d\n", n);

  int step = 0;

  int count_0 = 0, count_1 = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(arr[i][j] == 0){
        count_0++;
      }else{
        count_1++;
      }
    }
  }
  if(count_0 < count_1){
    //  swap...
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        swap_0_1(&arr[i][j]);
      }
    }
    step++;
    printf("n = %d\n", n);
  }
  printf("n = %d\n", n);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("???\n");

  int start_row, start_col, end_row, end_col;
  for(int start_row = 0; start_row < n; ++start_row){
    for(int start_col = 0; start_col < n; ++start_col){
      if(arr[start_row][start_col] == 1){
        printf("%d  %d  %d  %d\n", start_row, start_col, end_row, end_col);
        end_row = start_row;
        printf("%d  %d  %d  %d\n", start_row, start_col, end_row, end_col);
        for(int j = start_col; j < n; ++j){
          if(arr[start_row][j] == 0){
            end_col = j - 1;
            printf("%d  %d  %d  %d\n", start_row, start_col, end_row, end_col);
            end_row++;
            break;
          }
        }
        for(int i = start_row + 1; i < n; ++i){
          for(int j = start_col; j <= end_col; ++j){
            if(arr[i][j] == 0){
              end_row--;
              printf("%d  %d  %d  %d\n", start_row, start_col, end_row, end_col);
              printf("OK\n");
              step++;
              i = n;
              break;
            }else{
              end_row++;
            }
          }
        }
        printf("%d  %d  %d  %d\nend\n", start_row, start_col, end_row, end_col);
        //  swap...
        for(int i = start_row; i <= end_row; ++i){
          for(int j = start_col; j <= end_col; ++j){
            swap_0_1(&arr[i][j]);
          }
        }
      }
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  printf("%d", step);
  return 0;
}
