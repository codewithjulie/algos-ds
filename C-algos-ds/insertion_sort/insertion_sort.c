#include <stdio.h>

/*

Big O (n**2)
Big Omega (n)
int arr[6] = {5, 2, 1, 6, 3, 4};


| 5 2 1 6 3 4
5 | 2 1 6 3 4
2 5 | 1 6 3 4
2 5 5 1 6 3 4
2 2 5 1 6 3 4
1 2 5 | 6 3 4
1 2 5 6 | 3 4
1 2 3 5 6 | 4
1 2 3 4 5 6 |

*/

void swap(int *a, int *b);
void method1(int arr[], int length);
void method2(int arr[], int length);
void method3(int arr[], int length);
void print(int arr[], int length);

int main(void)
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int length = 6;
    method1(arr, length);  // Choose 1 of 3 methods here
    print(arr, length);
}

void method1(int arr[], int length)
{
    int temp;
    for (int i = 1; i < length; i++) // loop through array
    {
        for (int j=0; j < i; j++) // to compare i to j
        {
            if (arr[i] < arr[j]) // if left less than current
            {
                temp = arr[j];  //temp = 5
                arr[j] = arr[i]; // arr[0] = 2
                arr[i] = temp; // arr[1] = 5
            }
        }
    } 
}

void method2(int arr[], int length)
{
    int target, j;
    // Loop through the array
    for (int i = 1; i < length; i++)
    {
        // Target here is the first unsorted element
        target = arr[i];

        // j is the index of the last sorted element
        j = i - 1;

        // Shifts the sorted elements to make room for target
        while (arr[j] > target && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Place the target into place
        arr[j + 1] = target;
    }
}

void method3(int arr[], int length)
{
    int key = 1;
    for (; key < length; key++) 
    {
        for (int i = key - 1; i >= 0; i --) 
        {
            if (arr[i+1] < arr[i]) 
            {
                swap(&arr[i+1], &arr[i]);
            }
            else 
            {
            break;
            }
        }
    }
}

void print(int arr[], int length)
{
    printf("Sorted array is: \n");
    for (int i = 0; i < length; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}