#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int unitt(const void *a){
    if(*(int*)a % 2 != 0 && *(int*)a < 0){
        return 1;
    }
    else
        return 0;
}

int unitd(const void *a){
    double fpart;
    double ipart;
    fpart = modf(*(double*)a, &ipart);
    if(fpart == 0 && (int)ipart % 2 == 0)
        return 1;
    else
        return 0;
}

int count_if(void *base, size_t num, size_t size, int(*pred)(const void*)){
    int val = 0;
    for(int i = 0; i < num; i++)
        if(pred(base+i*size))
            val++;
    return val;
}

int main(){
    int input;
    scanf("%d", &input);
    void *arr = 0;
    switch(input){
        case 4:
            arr = malloc(sizeof(input)*5);
            for(int i = 0; i<5; i++)
                scanf("%d", arr+i*input);
            printf("%d\n", count_if(arr, 5, input, unitt));
            break;
        case 8:
            arr = malloc(sizeof(input)*5);
            for(int i = 0; i<5; i++)
                scanf("%lf", arr+i*input);
            printf("%d\n", count_if(arr, 5, input, unitd));
            break;
    }

}