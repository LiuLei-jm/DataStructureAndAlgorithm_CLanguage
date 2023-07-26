#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getIntergraPart(double num){
    int n = (int)num;
    return n;
}

int getFractionalPart(double num, int decPlaces){
    double amountToAdd = 0.5;
    for(int i = 0; i < decPlaces; i++){
        amountToAdd /= 10;
    }
    num += amountToAdd;
    int n = (int)num;
    num = num - n;
    for(int i = 0; i< decPlaces; i++){
        num *= 10;
    }
    return (int)num;
}

void PrintDigit(double num, int decPlaces){
    if(num < 0) {
        printf("-");
        num = fabs(num);
    }

    int integralPart = getIntergraPart(num);
    int fractionalPart = getFractionalPart(num, decPlaces);
    
    printf("%d", integralPart);
    if(fractionalPart > 0){
        printf(".%d", fractionalPart);
    }
    putchar('\n');
}

int main(){
    PrintDigit(-1231423.12356456, 3);

    system("pause");
    return 0; 
    }