#include <stdio.h>
#include <stdlib.h>

int a[] = {1,2,3,4,5,6,7,8,9};

void adjust(int i, int m){
    int j;
    for(j = i; j > 0; j--){
        a[j] = a[j-1];
    }
    a[0] = m;
}

int main(){
    int m;
    int i;
    int alen = sizeof(a)/sizeof(int);
    while(scanf("%d", &m) == 1){
        i = 0;
        while(a[i] != '\0'){
            if(a[i] == m){
                adjust(i, m);
                break;
            }
            else{
                i++;
            }
        }
        if(i == alen){
            printf("Not found!\n");
        }
        else{
            for(i = 0; i < alen - 1; i++){
                printf("%d ", a[i]);
            }
            printf("%d\n",a[alen-1]);
        }
    }
    system("Pause");
    return 0;
}