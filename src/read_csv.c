#include "read_csv.h"

error_t csv_read(const char* _path_to_csvfile, FILE **_filepntr, int *_no_of_lines){
        
        *_filepntr = fopen(_path_to_csvfile, "r");
        *_no_of_lines = 0;

        if(*_filepntr == NULL){
            return FAILURE;
        }
        char c;
        while( ( c = getc(*_filepntr) ) != EOF )
            (*_no_of_lines) += (c == '\n')?1:0;

        fseek(*_filepntr, 0, SEEK_SET);
        return SUCCESS;
}

error_t csv_disp_ln(FILE **_filepntr){
    
    if( *_filepntr == NULL){
        return FAILURE;
    }

    char c, buffer[1024];
    int i = 0;
    int indx = 0;
    char headers[3][10] = {"Name: ","Email: ","Github: "};
    
    while( ( c = getc(*_filepntr) ) != EOF ){
        if(c == ',' || c == '\n'){
            buffer[i] = '\0';
            printf("%s%s\n", headers[indx], buffer);
            indx ++;
            if(indx > 2){
                indx = 0;
                printf("\n");
            }
            i = 0;
            continue;
        }
        else{
        buffer[i] = c;
        }
        i++;
    }
    fseek(*_filepntr, 0, SEEK_SET);
    return SUCCESS;
}

error_t csv_close(FILE **_filepntr){      
        if( *_filepntr == NULL ) return FAILURE;
        fclose(*_filepntr);
        return SUCCESS;
}