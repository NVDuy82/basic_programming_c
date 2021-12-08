#include <stdio.h>

int main(){
    int n;

    // Nhap hang, cot
    printf("Nhap cap cho Ma tran:");
    scanf("%d", &n);

    float arr[n][n];
    // Nhap gia tri cho ma tran
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Nhap hang %d cot %d:", i+1, j+1);
            scanf("%f", &arr[i][j]);
        }
    }

    // In ra ma tran
    printf("\n\n\n\n\n\n\n\n\n\n\n\n--------------------------------------\n\n");
    printf(" _");
    for (int i = 0; i < 9*n+n; ++i) {
        printf(" ");
    }
    printf("_ \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("|   %2.2f   ", arr[i][j]);
        }
        printf("|\n");
    }
    printf("|_");
    for (int i = 0; i < 9*n+n; ++i) {
        printf(" ");
    }
    printf("_|\n");


    //                  ----------------------------------

    // Tim tich cot hho nhat
    float old_Tich = 9999999;
    for (int j = 0; j < n; ++j) {
        float new_Tich = 1;
        for (int i = 0; i < n; ++i) {
            new_Tich = new_Tich * arr[i][j];
        }
        if (new_Tich < old_Tich){
            old_Tich = new_Tich;
        }
    }
    printf("Nho nhat: %f\n", old_Tich);

    // mảng n phẩn tử, 1 pt = 1 float =>  100pt => 100 float  1.000.000 => 1.000.000 float  =>  4/8mb
    //  2 float   =>   16 byte

    // Tong cheo phu
    float sum_cheophu = 0;
    for (int i = 0; i < n; ++i) {
        sum_cheophu += arr[i][n-i-1];
    }
    printf("Tong cheo phu: %.2f\n", sum_cheophu);


    // Kiem tra ma tran tam giac duoi
    int bTamGiacDuoi = 1;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i][j] != 0){
                bTamGiacDuoi = 0;
                // Thoat khoi for
                break;
            }
        }
        if (bTamGiacDuoi == 0){
            break;
        }
    }
    // Kiem tra ma tran tam giac tren
    int bTamGiacTren = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i][j] != 0){
                bTamGiacTren = 0;
                // Thoat khoi for
                break;
            }
        }
        if (bTamGiacTren == 0){
            break;
        }
    }
    if (bTamGiacTren == 1 && bTamGiacDuoi == 1){
        printf("Ma tran vua la ma tran tam giac tren, vua la ma tran tam giac duoi\n");
    } else if (bTamGiacTren == 1){
        printf("Ma tran la ma tran tam giac tren\n");
    } else if (bTamGiacDuoi == 1){
        printf("Ma tran la ma tran tam giac duoi\n");
    } else {
        printf("Ma tran khong la ma tran tam giac\n");
    }

    // Kiem tra ma phương
    char isMagicSquare = 1;
    float old_sum_MS, sum_MS;
    // kiem tra cac hang
    for (int i = 0; i < n; ++i) {
        old_sum_MS = sum_MS;
        sum_MS = 0;
        for (int j = 0; j < n; ++j) {
            sum_MS += arr[i][j];
        }
        if (old_sum_MS != sum_MS && i != 0){
            isMagicSquare = 0;
            break;
        }
    }
    // kiem tra cac cot
    if (isMagicSquare){
        for (int j = 0; j < n; ++j) {
            old_sum_MS = sum_MS;
            sum_MS = 0;
            for (int i = 0; i < n; ++i) {
                sum_MS += arr[i][j];
            }
            if (old_sum_MS != sum_MS){
                isMagicSquare = 0;
                break;
            }
        }
    }
    // kiem tra cheo phu
    if (isMagicSquare){
        old_sum_MS = sum_MS;
        sum_MS = sum_cheophu;
        if (old_sum_MS != sum_MS){
            isMagicSquare = 0;
        }
    }
    // kiem tra cheo chinh
    if (isMagicSquare){
        old_sum_MS = sum_MS;
        sum_MS = 0;
        for (int i = 0; i < n; ++i) {
            sum_MS += arr[i][i];
        }
        if (old_sum_MS != sum_MS){
            isMagicSquare = 0;
        }
    }
    if (isMagicSquare){
        printf("Matrix is Magic Square...\n");
    } else{
        printf("Matrix is not Magic Square...\n");
    }

    return 0;
}
