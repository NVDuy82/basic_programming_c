#include <stdio.h>
#include <string.h>

void creatlist(char (*listS)[200], int *lens, char *s){
  int i, j = 0, cur = 0;
  for(i = 0; i < 200; i++){
    if(s[i] != ' ' && s[i] != '\0'){
      while(s[i] != ' ' && s[i] != '\0'){
        listS[cur][j] = s[i];
        i++;
        j++;
      }
      listS[cur][j] = '\0';
      j = 0;
      for(int k = 0; k < cur; k++){
        int compare = strcmp(listS[k], listS[cur]);
        if(compare > 0){
          char temp[200];
          strcpy(temp, listS[k]);
          strcpy(listS[k], listS[cur]);
          strcpy(listS[cur], temp);
        } else if(compare == 0){
          listS[cur][0] = '\0';
          cur--;
        }
      }
      cur++;
    }
  }
  *lens = cur + 1;
}

void run(char (*listS1)[200], int len1, char (*listS2)[200], int len2){
  for(int i = 0; i < len1; i++){
    int ok = 1;
    for(int j = 0; j < len2; j++)
      if(!strcmp(listS1[i],listS2[j])){
        ok = 0;
        break;
      }
    if(ok) printf("%s ",listS1[i]);
  }
}

int main() {  
  char S1[200], S2[200], listS1[90][200], listS2[90][200];  
  int len1, len2;
  fgets(S1, sizeof S1, stdin);
  fgets(S2, sizeof S2, stdin);
  creatlist(listS1, &len1, S1);
  creatlist(listS2, &len2, S2);
  run(listS1, len1, listS2, len2);  
  return 0;
}
