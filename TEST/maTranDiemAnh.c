#include <stdio.h>

void program(){
  int n, m;
  do{
    scanf("%d%d", &n, &m);
  } while(1000 < n || 1000 < m); // n, m <= 1 000

  int matrix[n][m];  // matrix n * m
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){      
      do{
        scanf("%d", &matrix[i][j]);
      } while(matrix[i][j] < 0 || 2 < matrix[i][j]); // matrix[i][j] = 0 / 1 / 2
    }
  }

  int out = 0;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){      
      if (matrix[i][j]){
        int ok = (1 + 2) - matrix[i][j]; // ok <> matrix[i][j]
        int add = 0;
        for(int row = 0; row < n; ++row){
          add += (matrix[row][j] == ok) ? 1 : 0;
        }
        for(int col = 0; col < n; ++col){
          add += (matrix[i][col] == ok) ? 1 : 0;
        }
        out += add / 2;
      }
    }
  }
  printf("%d", out);
}

int main() {
  int cases; // number of cases
  scanf("%d", &cases);

  for(int i = 0; i < cases; ++i){
    program();
  }

  return 0;
}