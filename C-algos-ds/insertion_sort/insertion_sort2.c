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

int main(void)
{
    int length = 6;
    int arr[] = {6, 5, 4, 3, 2, 1};
    //int arr[] = {1, 2, 3, 4, 5, 6};
    int temp;
    int target, j;
    int steps = 0;
    int swaps = 0;
    int comparisons = 0;
    int flag;
    // Loop through the array

    // Compare to elements to the left of current element

    // If current element is smaller, then move left element to current element location

    // for (int i=1; i < length; i++) // loop through array
    // {
    //   for (int j=0; j < i; j++) // to compare i to j
    //   {
    //     if (arr[i] < arr[j]) // if left less than current
    //     {
    //       temp = arr[j];  //temp = 5
    //       arr[j] = arr[i]; // arr[0] = 2
    //       arr[i] = temp; // arr[1] = 5
    //       swaps++;
    //     }
    //     comparisons++;
    //   }
    //   comparisons++;
    // } 

   /* for (int i = 1; i < length; i++)
    {
        target = arr[i];
        j = i - 1;
        flag = 0;
        while (arr[j] > target && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
            comparisons++;
            flag++;
        }
        
        arr[j + 1] = target;
        if (flag == 0)
          comparisons++;

    } */

int key = 1;
for (; key < length; key++) {
    for (int i = key - 1; i >= 0; i --) {
      if (arr[i+1] < arr[i]) {
	      swap(&arr[i+1], &arr[i]);
        swaps++;
      }
      else {
        break;
      }
      comparisons++;
    }
    comparisons++;
  }

  printf("Sorted array is: \n");
  for (int i = 0; i < length; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
  
  printf("Swaps are: %d and Comparisons are: %d\n", swaps, comparisons);
}


void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}