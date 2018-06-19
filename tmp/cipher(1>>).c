#include <stdio.h>
#include <string.h>

 int main(){
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < (len >> 1); ++i)
        printf("%c%c", str[i], str[i+((len+1)>>1)]);
    if(len & 1)
        printf("%c", str[(len >> 1)]);;
 }