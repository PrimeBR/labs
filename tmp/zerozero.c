#include <stdio.h>

int recursion(){
    int first,second;
    scanf("%d", &first);
    if(first == 1)
        second++;
    if(first == 0){
        scanf("%d", &first);
        if(first == 0)
            return 0;
        if(first == 1)
            second++;
    }
    second += recursion();
    return second;
}
int main(){
    printf("result:%d\n", recursion());
    return 0;
}