#include <stdio.h>

struct SV{
  int msv;
  char hoten[30];
  char khoa;
  float diem;
};

int main() {
  int n;
  printf("Nhap n: ");
  scanf("%d", &n);
  struct SV sv[n];

  for(int i = 0; i < n; ++i){    
    printf("Nhap ma sinh vien cho sv thu %d: ", i + 1);
    scanf("%d", &sv[i].msv);
    printf("Nhap ho ten cho sv thu %d: ", i + 1);
    scanf("%s", sv[i].hoten);
    printf("Nhap khoa cho sv thu %d: ", i + 1);    
    scanf("%c", &sv[i].khoa);
    printf("Nhap diem cho sv thu %d: ", i + 1);
    scanf("%f", &sv[i].diem);
  }

  printf("Thong tin sv:\n");
  for(int i = 0; i < n; ++i){
    printf("%d \t %s \t %c \t %f \n", sv[i].msv, sv[i].hoten, sv[i].khoa, sv[i].diem);
  }
  
  return 0;
}