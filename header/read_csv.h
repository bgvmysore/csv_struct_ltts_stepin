#pragma once
/**
 * @file read_csv.h
 * @author Bhargav R
 * @brief This contains functions that reads csv file, store it into an array, and sort it. 
 * @version 0.1
 * @date 2021-03-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief This is a struct to store each line from the csv file which is in format name, email, git link.
 * 
 */
typedef struct info_t {
    char* name;
    char* email_id;
    char* git_link;
} info_t;

/**
 * @brief Error codes. It helps in testing of functions.
 * 
 */
typedef enum error_t{
    SUCCESS = 0,
    FAILURE = -1
}error_t;

/**
 * @brief This function reads the csv file and gives file pointer pointing to csv file, and no of line.
 * 
 * @param _path_to_csvfile (char *) path to csv file.
 * @param _filepntr (FILE **) csv file pointer is strored in this double pointer.
 * @param _no_of_lines (int *) no of lines is stored in the var pointed by this pointer.
 * @return error_t Returns error codes, success or failure.
 */
error_t csv_read(const char* _path_to_csvfile, FILE **_filepntr, int *_no_of_lines);

/**
 * @brief Prints the contents of the csv file in a formatted way.
 * 
 * @param _filepntr (FILE **) csv file pointer is strored in this double pointer.
 * @return error_t Returns error codes, success or failure.
 */
error_t csv_disp_ln(FILE **_filepntr);

/**
 * @brief Closes the opened csv file.
 * 
 * @param _filepntr (FILE **) csv file pointer is strored in this double pointer.
 * @return error_t Returns error codes, success or failure.
 */
error_t csv_close(FILE **_filepntr);

/**
 * @brief Reads the csv file and stores each row as info_t struct object into an array.
 * 
 * @param _filepntr (FILE **) csv file pointer is strored in this double pointer.
 * @param _no_of_lines (int *) No of lines in csv file which is also length of array.
 * @param _array_info_t (info_t*) array of info_t struct objects.  
 * @return error_t Returns error codes, success or failure.
 */
error_t csv_to_arr(FILE **_filepntr, int *_no_of_lines, info_t* _array_info_t);

/**
 * @brief Sort the array of info_t objects in alphabatical order.
 * 
 * @param _array_info_t (info_t*) array of info_t struct objects.
 * @param _no_of_lines (int *) No of lines in csv file which is also length of array.
 * @return error_t Returns error codes, success or failure.
 */
error_t csv_arr_sort(info_t* _array_info_t, int *_no_of_lines);

/**
 * @brief Free the memory of array of info_t objects and also char pointers in info_t object.
 * 
 * @param _array_info_t (info_t*) array of info_t struct objects.
 * @param _no_of_lines (int *) No of lines in csv file which is also length of array.
 * @return error_t Returns error codes, success or failure.
 */
error_t csv_arr_free(info_t* _array_info_t, int *_no_of_lines);

/**
 * @brief Display info_t object in a formatted line.
 * 
 * @param _info_t_obj (info_t *) Pointer to info_t object which is to be displayed.
 * @return error_t Returns error codes, success or failure.
 */
error_t disp_info_t(info_t const* _info_t_obj);

/**
 * @brief Comparision function used in sorting of info_t objects
 * 
 * @param _info_t_a Pointer to info_t 1st object.
 * @param _info_t_b Pointer to info_t 2nd object.
 * @return int Returns output of strcmp of name member of above two info_t objects.
 */
int alphabaticalorder(const void * _info_t_a, const void * _info_t_b);