#include <stdio.h>
#include <string.h>

int main(){
    char crypt[50];
    fgets(crypt, 51, stdin);
    char key[50];
    scanf("%s", key);
    int x = (int)crypt[0]-(int)crypt[1];
    printf("[%s] [%s] [%d]\n", crypt, key, x);
    for(int i = 0; i < strlen(key); i++)
        if(x == (crypt[i-1]- crypt[i]) || x == (crypt[0]-crypt[strlen(key)])){
            printf("Result:-1\n");
            break;
    }
}