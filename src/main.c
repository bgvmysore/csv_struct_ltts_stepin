#include <stdio.h>
#include <stdlib.h>
#include "../header/read_csv.h"

int main(){
    FILE *fptr;
    fptr = fopen("./data.csv", "r");
    if(fptr == NULL){
        printf("Error opening file!\n");
    }
    char c, buffer[1024];
    int i = 0;
    while( ( c = getc(fptr) ) != EOF ){
        if(c == ',' || c == '\n'){
            buffer[i] = '\0';
            printf("%s\n", buffer);
            i = 0;
            continue;
        }
        else{
        buffer[i] = c;
        }
        i++;
    }
    fclose(fptr);
    return 0;
}