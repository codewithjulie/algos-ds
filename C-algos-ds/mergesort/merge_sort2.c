 //1st MS divide and conquer. 

//2nd In-place - doesn`t take extra memory (like insertion sort), while merger requiers buffer to hold temporary value.

//1    1, 6, 10, 60 29, 11, 56
//1, 6, 10,     60 29, 11, 56
//1, 6,    10,     60 29,    11, 56
//....
//N-1  1,6   10, 60   11,29,  56
// N   1,    6,    10,     60,     29,    11,    56
// n elements and N levels

//BigO(n logn)   log base 2 to n

#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int arr_len);
void merge_sort(int *arr, int strt, int end);
void merge(int *arr, int strt, int mid, int end);

int main(void) {
  //int arr[] = {6, 1, 10, 60, -5, 5, 0, 33, 30};
  //int arr[] = {35, 0, -109, 55, 645, 91, -99, 100, 4};
  int arr[] = {5, 1, 3, 8, 6, 4, 2, 7};
  int arr_len = sizeof(arr) / sizeof(arr[0]);
  print_arr(arr, arr_len);
  merge_sort(arr, 0, arr_len - 1);
  print_arr(arr, arr_len);
}

void merge_sort(int *arr, int strt, int end) {
  if (strt < end) {                 //base case for our recursion. Checking for valid array.
    int mid = (end + strt) / 2;     //calculate middle an array
    merge_sort(arr, strt, mid);     //prepare left part of an array
    merge_sort(arr, mid + 1, end);  //prepare right part of an array
    merge(arr, strt, mid, end);     //sort left and right part
  }
}

void merge(int *arr, int strt, int mid, int end) {
  //int *tmp_arr = malloc(sizeof *tmp_arr * (end - strt));   //temporary array / int tmp_arr[]
  printf("MERGE!\n");
  //print_arr(arr, 9);
  printf("Start is %i and end is %i and middle is %i\n", strt, end, mid);
  int tmp_arr[end - strt];
  int i = strt;             //interator for "for" loop for left part
  int k = mid + 1;          //interator for "for" loop for right part
  int j = 0;             //interator for "for" loop for temp arr
  printf("End - strt + 1 is %i\n", end - strt + 1);
  
  while ((i <= mid) && (k <= end)) {   //main iteration and comparison of elements form two parts of parent array
    printf("WHILE LOOP\n");
    if (arr[i] < arr[k]) {
      tmp_arr[j] = arr[i];
      i++;
      j++;
      printf("LEFT!!!!!!!!\n");
    }
    else {
      tmp_arr[j] = arr[k];
      k++;
      j++;
      printf("RIGHT!!!!!!!!\n");
    }
       printf("Start is %i and end is %i and middle is %i and i is %i and k is is %i and j is %i\n"
            , strt, end, mid, i, k, j);
  }
  printf("End - strt + 1 is %i\n", end - strt + 1);
  while (i <= mid) {                  //check if we have missing elements in left part
      tmp_arr[j] = arr[i];
      i++;
      j++;
  }
 
  while (k <= end) {                  //check if we have missing elements in right part
      tmp_arr[j] = arr[k];
      k++;
      j++;
  }
/*
  for (i = strt; i < k; i++) {

    arr[i] = tmp_arr[i];
  }
  // free(tmp_arr);
}
*/
  int l = 0;
  int m = strt;
  for (; l < j; ) {

    arr[m] = tmp_arr[l];
    l++;
    m++;
  }

  // free(tmp_arr); 
}

void print_arr(int *arr, int arr_len) {
  for(int i = 0; i < arr_len; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
}