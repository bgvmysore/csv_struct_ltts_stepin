#include "read_csv.h"

error_t csv_read(const char* _path_to_csvfile){
        FILE *_filepntr = fopen(_path_to_csvfile, "r");
        if(_filepntr == NULL){
            printf("Error opening file!\n");
            return FAILURE;
        }
        char c, buffer[1024];
        int i = 0;
        while( ( c = getc(_filepntr) ) != EOF ){
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
        fclose(_filepntr);
        return SUCCESS;
}