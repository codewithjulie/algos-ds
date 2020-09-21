//Divide and conquer 
//Sorts in place
//Can be adjusted easily
//Big-O(n log n) on average
//Big-O(n^2) in worst case

//It s like merge sort, but without
//allocating new memory every time and
//all the work is done on a division step,
//not in combination step.

//Steps
//1)Divide - partitioning on two subarrays with a pivot, 
//putting all the elements lesser or equal to pivot to
//the left of the pivot, greater - to the right.
//2)Reqursion - do the same with two subarrays, each of
//which doesn`t include pivot
//3)Combine - do nothing as it is already sorted.

#include <stdio.h>

void print_arr(int *arr, int arr_size);
void qs(int *arr, int lo, int hi);
int partion(int *arr, int lo, int hi);
void swap(int *a, int *b);

int main(void) {
  //int arr[] = { 6, 2, 5, 0, 1, 10, -1, 3, 4, 9, 8, -2, 7 };
  int arr[] = { 2, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1, 1, 0 };
  int arr_size = sizeof(arr) / sizeof(*arr);

  print_arr(arr, arr_size);
  
  qs(arr, 0, arr_size);

  print_arr(arr, arr_size);
}

void qs(int *arr, int lo, int hi) {
  if (lo>=hi) { //CHECK AFTERWARDS
    ;
  }
  else {
    int p = partion(arr, lo, hi);
    qs(arr, lo, p);
    qs(arr, p+1, hi);
  }
}

int partion(int *arr, int lo, int hi) {
  int i, j, p;
  p = hi-1;
  i = lo; //a boundary for elements <= p
  j = lo; //a boundary for elements >  p
  //lo - i are the elem <= p
  //i - j are the elem > p
  //j - p are not evaluated yet

  for ( ; j < p; j++) {
    if (arr[j] <= arr[p]) {
      swap(&arr[j], &arr[i]);
      i++;
    }
  }
  swap(&arr[p], &arr[i]);
  p = i;
  return p;
}

void print_arr(int *arr, int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}