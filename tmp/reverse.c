#include <stdio.h>
#include <string.h>
int rec(int n){
    if(n<1)
        return 1;
	printf("%d", n%10);
    rec(n/=10);

};


int main(){
    int n;
	scanf("%d", &n);    
	rec(n);
    return 0;           
}