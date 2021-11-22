#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

struct tup2 {
    float x1;
    char b1;
    float x2;
    char b2;
};

struct tup2 x2quadratic(const float a, const float b, const float c){
    struct tup2 res;
    res.b1 = res.b2 = 1;

    if (a == 0){
        res.b2 = 0;
        if (b == 0){
            if (c == 0){
                // ????????
            } else {
                res.b1 = 0;
            }
        } else {
            res.x1 = -c / b;
        }
    } else {
        float dComma = b * b / 4 - a * c;
        if (dComma == 0) {
            res.x1 = res.x2 = -b / (2 * a);
        } else if (dComma > 0) {
            res.x1 = (-b / 2 - sqrt(dComma)) / a;
            res.x2 = (-b / 2 + sqrt(dComma)) / a;
        } else {
            res.b1 = 0;
            res.b2 = 0;
        }
    }
    return res;
}

float FtoC(float f){
    return (f-32) / 1.8;
}

float CtoF(float c){
    return 1.8*c + 32;
}

int main() {
    int run = 1;
    float c, f;

    printf("Enter F: ");
    scanf("%f", &f);
    c = FtoC(f);
    printf("%.2f F to %.2f C\n", f, c);

    //End main
    return 0;
}