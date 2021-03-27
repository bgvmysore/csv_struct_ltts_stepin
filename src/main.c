#include <stdio.h>
#include <stdlib.h>
#include "../header/read_csv.h"

int main(){
    FILE *fptr;
    fptr = fopen("./data.csv", "r");
    csv_read("./data.csv");
    return 0;
}