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

error_t csv_to_arr(FILE **_filepntr, int *_no_of_lines, info_t* _array_info_t){
    if(*_filepntr == NULL || _no_of_lines == NULL || _array_info_t == NULL ) return FAILURE;
    for(int i=0; i< *_no_of_lines ; i++){
        char buffer[1024], c;
        int j = 0;
        short comma_cnt = 0;
        do{
            c = getc(*_filepntr);
            if(c == ',' || c == '\n'){
                buffer[j] = '\0';
                if(comma_cnt == 0){
                    ( *(_array_info_t+i) ).name = malloc(strlen(buffer)*sizeof(char));
                    strcpy(( *(_array_info_t+i) ).name, buffer);
                    comma_cnt ++;
                }
                else if(comma_cnt == 1){
                    ( *(_array_info_t+i) ).email_id = malloc(strlen(buffer)*sizeof(char));
                    strcpy(( *(_array_info_t+i) ).email_id, buffer);
                    comma_cnt++;
                }
                else if(comma_cnt == 2){
                    ( *(_array_info_t+i) ).git_link = malloc(strlen(buffer)*sizeof(char));
                    strcpy(( *(_array_info_t+i) ).git_link, buffer);
                    comma_cnt = 0;
                }
                j = 0;
            }
            else{
                buffer[j] = c;
                j++;
            }
        }while( c  != '\n');
    }
    fseek(*_filepntr, 0, SEEK_SET);
    return SUCCESS;
}

error_t free_csv_arr(info_t* _array_info_t, int *_no_of_lines){
    if(_no_of_lines == NULL || _array_info_t == NULL) return FAILURE;
    for(int i=0; i< *_no_of_lines; i++){
        free( ( *(_array_info_t+i) ).name );
        free( ( *(_array_info_t+i) ).email_id );
        free( ( *(_array_info_t+i) ).git_link );
    }
    free( _array_info_t );
    *_no_of_lines = 0;
    return SUCCESS;
}