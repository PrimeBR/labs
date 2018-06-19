#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Resource{
    char resource[20];
    int volume;
};

int comp(const void *a, const void *b){
    return strcmp((*(struct Resource*)a).resource, (*(struct Resource*)b).resource);
}

int main(){
    int count = 0;
    int size = 1;
    struct Resource *res = (struct Resource*)malloc(sizeof(struct Resource)*size);    
    while(1){
        struct Resource buffer;
        scanf("%s", buffer.resource);
        if(!strcmp(buffer.resource, "Total"))
            break;
        scanf("%d", &buffer.volume);
        for(int i = 0; i < strlen(buffer.resource); i++)
            buffer.resource[i] = (char)tolower(buffer.resource[i]);
        struct Resource *repeat = bsearch(&buffer, res, count, sizeof(struct Resource), comp);
        if(repeat){
            repeat->volume += buffer.volume;
            continue;
        }
        if(count == size){
            size <<=1;
            res = (struct Resource*)realloc(res, size*sizeof(struct Resource));
        }
        res[count] = buffer;
        count++;
        qsort(res, count, sizeof(struct Resource), comp);
    }

    for(int i = 0; i < count; i++)
        printf("%s %d\n", res[i].resource, res[i].volume);

}
