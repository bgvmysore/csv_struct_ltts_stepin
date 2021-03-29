#include <stdio.h>
#include <stdlib.h>
#include "../header/read_csv.h"

int main(){
    FILE *fptr;
    int nLn;

    csv_read("./data.csv", &fptr, &nLn);

    printf("No of lines in csv file: %d\n\n", nLn);

    csv_disp_ln(&fptr);

    csv_close(&fptr);
    
    return 0;
}