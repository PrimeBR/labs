#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%d ", &N);
    char str[100];
    fgets(str, 101, stdin);
    for(int i = 0; i<strlen(str); i++)
        printf("%c", (26 - N%26 + str[i] - 'a')%26 + 'a');

}