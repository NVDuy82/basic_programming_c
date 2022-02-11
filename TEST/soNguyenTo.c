#include <stdio.h>
#include <math.h>

char check(int n){
  if(n < 2) return 0;
  for(int i = 2; i <= round(sqrt(n)); i++){
    if(!(n % i)) return 0;
  }
  return 1;
}

int main() {
  unsigned int n;
	printf("Nhap vao so nguyen duong n: ");
	scanf("%d", &n);

  printf("%d", n);
  if(check(n))
		printf(" la so nguyen to!");
	else
		printf(" khong la so nguyen to!");
  return 0;
}
