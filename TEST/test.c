#include <stdio.h>

int main() {
  int n;
  printf("Nhap n: ");
  scanf("%d", &n);
  float arr[n];

  for(int i = 0; i < n; ++i){    
    printf("Nhap so thu %d: ", i + 1);
    scanf("%f", &arr[i]);
  }

  printf("Day vua nhap la: ");
  for(int i = 0; i < n; ++i){    
    printf("%.2f  ", arr[i]);
  }

  printf("\n Trung binh cong cac so chia het cho 3 hoac 4: ");
  float sum;
  int count;
  for(int i = 0; i < n; ++i){
    int val = round(arr[i]);
    if(arr[i] == val && (val % 3 == 0 || val % 4 == 0)){
      sum += arr[i];
      count++;      
    }
  }
  float res = sum / count;
  printf("%f\n", res);
  
  return 0;
}
  
