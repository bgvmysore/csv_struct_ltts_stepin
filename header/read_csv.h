#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct info_t {
    char* name;
    char* email_id;
    char* git_link;
} info_t;

typedef enum error_t{
    SUCCESS = 0,
    FAILURE = -1
}error_t;

error_t csv_read(const char* _path_to_csvfile, FILE **_filepntr);

error_t csv_disp_ln(FILE **_filepntr);

error_t csv_close(FILE **_filepntr);
