#include <stdio.h>

int recursion(){
    int fstep, secstep, thirdstep;
    scanf("%d", &fstep);
    if(fstep == 1){
        scanf("%d", &secstep);
        if(secstep == 1)
            return recursion() + fstep + secstep;
        else if(secstep == 0){
            scanf("%d", &thirdstep);
            if(thirdstep == 1)
                return recursion() + fstep + secstep + thirdstep;
            else if(thirdstep == 0)
                return fstep + secstep;
            else
                return recursion() + fstep;
        }
    else 
        return recursion() + fstep;
    }
    else if(fstep == 0){
        scanf("%d", &secstep);
        if(secstep == 1)
            return recursion() + secstep;
        else if(secstep == 0)
            return 0;
        else
            return recursion();
    }
    else
        return recursion();
}

int main(){
    printf("result:%d", recursion());
    return 0;
}