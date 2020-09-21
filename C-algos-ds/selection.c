//{31, 41, 59, 26, 41, 58};

// 26 | 41, 59, 31, 41, 58
// 26, 31, | 59, 41, 41, 58
// 26 31 41 | 59 41 58
// 26 31 41 41 | 59 58
// 26 31 41 41 58 | 59
// 26 31 41 41 58 59

#include <stdio.h>


int main(void)
{
    int A[6] = {31, 41, 59, 26, 41, 58};
    int min, temp;
    for (int i = 0; i < 6; i++)
    {
        min = i;
        for (int j = i + 1; j < 6; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if(i != min)
        {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%i\t", A[i]);
    }
}