#include <stdio.h>
#include <stdlib.h>
#include "../header/read_csv.h"

int main(){
    FILE *fptr;
    csv_read("./data.csv", &fptr);
    csv_disp_ln(&fptr);
    csv_close(&fptr);
    return 0;
}