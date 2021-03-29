#include <stdio.h>
#include <stdlib.h>
#include "../header/read_csv.h"

int main(){
    FILE *fptr;
    int nLn;
    info_t* arr;

    csv_read("./data.csv", &fptr, &nLn);

    arr = malloc(nLn*sizeof(info_t));

    csv_to_arr(&fptr, &nLn, arr);

    printf("\n\n");
    for(int i=0; i<nLn; i++)
        printf("%s, %s, %s\n", arr[i].name, arr[i].email_id, arr[i].git_link);
     printf("\n\n");

    csv_arr_free(arr, &nLn);

    csv_disp_ln(&fptr);

    csv_close(&fptr);
    
    return 0;
}