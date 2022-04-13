#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
  int n;
  do {
    scanf("%d", &n);
  } while(n < 1 || 50 < n);  // 1 <= n <= 50

  char s[n][50];
  int unsigned len[n]; // length of s

  // enter s[i]
  scanf("%s", s[0]);
  len[0] = strlen(s[0]);
  int unsigned length = len[0];
  for(int i = 1; i < n; ++i){
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
    // different length
    if(len[i] != length){
      printf("%d", -1); // can't --> out
      return 0;
    }
    length = len[i];
  }

  int posn[n];  // position
  posn[0] = 0;
  for(int i = 1; i < n; ++i){
    int end = length;
    posn[i] = 0;
    int count = 0;
    for(int j = 0; j < end; ++j){
      if(s[i][j % length] != s[0][j - posn[i]]){        
        posn[i]++;
        end++;
      }else{
        count++;
      }
      if (end == length * 2) break;
    }
    // can't be transformed
    if(count != length){
      printf("%d", -1);  // --> out
      return 0;
    }
  }

  // step count
  int step = 0;
  float sum = 0;
  for(int i = 0; i < n; ++i){
    sum += posn[i];
  }
  int res = round(sum / n);
  for(int i = 0; i < n; ++i){
    step += (posn[i] + res) % length;
  }
  printf("%d", step);

  return 0;
}