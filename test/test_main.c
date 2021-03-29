#include "unity.h"
#include "read_csv.h"

void setUp(void){return;}

void tearDown(void){return;}

void test_csv_read(void){
    char * pathtoscv = "data.csv";
    int nofline = 0;
    FILE * myfptr;
    TEST_ASSERT_EQUAL_INT(SUCCESS, csv_read(pathtoscv, &myfptr, &nofline));
    TEST_ASSERT_EQUAL_INT(5, nofline);
    csv_close(&myfptr);
}

void test_csv_disp_ln(void){
    char * pathtoscv = "data.csv";
    int nofline = 0;
    FILE * myfptr;
    csv_read(pathtoscv, &myfptr, &nofline);
    TEST_ASSERT_EQUAL_INT(SUCCESS, csv_disp_ln(&myfptr));
    csv_close(&myfptr);
}

void test_csv_close(void){
    char * pathtoscv = "data.csv";
    int nofline = 0;
    FILE * myfptr;
    csv_read(pathtoscv, &myfptr, &nofline);
    TEST_ASSERT_EQUAL_INT(SUCCESS, csv_close(&myfptr));
}

void test_csv_to_arr(void){
    char * pathtoscv = "data.csv";
    int nofline = 0;
    FILE * myfptr;
    csv_read(pathtoscv, &myfptr, &nofline);
    info_t *arr;
    arr = malloc(nofline*sizeof(info_t));
    TEST_ASSERT_EQUAL_INT(SUCCESS, csv_to_arr(&myfptr, &nofline, arr));
    csv_close(&myfptr);
    csv_arr_free(arr, &nofline);
}

void test_disp_info_t(void){
    info_t a = {"Ram", "ram@ram.com", "github.com/ram.git"};
    TEST_ASSERT_EQUAL_INT(SUCCESS, disp_info_t(&a));
}

void test_csv_arr_sort(void){
    char * pathtoscv = "data.csv";
    int nofline = 0;
    FILE * myfptr;
    csv_read(pathtoscv, &myfptr, &nofline);
    info_t *arr;
    arr = malloc(nofline*sizeof(info_t));
    csv_to_arr(&myfptr, &nofline, arr);
    TEST_ASSERT_EQUAL_INT(SUCCESS, csv_arr_sort(arr, &nofline));
    TEST_ASSERT_EQUAL_STRING("Bgv", arr[0].name);
    TEST_ASSERT_EQUAL_STRING("Unity", arr[4].name);
    TEST_ASSERT_EQUAL_STRING("John wick", arr[2].name);
    csv_close(&myfptr);
    csv_arr_free(arr, &nofline);
}

void test_csv_arr_free(){
    char * pathtoscv = "data.csv";
    int nofline = 0;
    FILE * myfptr;
    csv_read(pathtoscv, &myfptr, &nofline);
    info_t *arr;
    arr = malloc(nofline*sizeof(info_t));
    csv_to_arr(&myfptr, &nofline, arr);
    TEST_ASSERT_EQUAL_INT(SUCCESS, csv_arr_free(arr, &nofline));
    csv_close(&myfptr);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_csv_read);
    RUN_TEST(test_csv_disp_ln);
    RUN_TEST(test_csv_close);
    RUN_TEST(test_csv_to_arr);
    RUN_TEST(test_disp_info_t);
    RUN_TEST(test_csv_arr_sort);
    RUN_TEST(test_csv_arr_free);

    return UNITY_END();
}