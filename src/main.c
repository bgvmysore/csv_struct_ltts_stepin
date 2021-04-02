#include <stdio.h>
#include <stdlib.h>
#include "../header/read_csv.h"

int main(){
    FILE *fptr = NULL;
    int nLn = 0;
    info_t* arr = NULL;

    csv_read("./data.csv", &fptr, &nLn);

    arr = malloc(nLn*sizeof(info_t));

    csv_to_arr(&fptr, &nLn, arr);

    csv_disp_ln(&fptr);

    csv_close(&fptr);

    csv_arr_sort(arr, &nLn);

    printf("\n");
    for(int i=0; i<nLn; i++)
        disp_info_t(&arr[i]);
     printf("\n\n");

    csv_arr_free(arr, &nLn);
    
    return 0;
}