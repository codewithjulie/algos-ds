# include <stdio.h>


int main(void)
{
    int A[6] = {31, 41, 59, 26, 41, 58};
    int i;
    for (i = 0; i < 6; i++)
    {
        if (A[i] == 31)
        {
            printf("found %i", i);
            return 0;
        }
    }

    printf("not found");
}



{A, B}
A =  1100
B =  1010
C = 10110
(n + 1)-element array C

A = {1, 1, 0, 1} n = 4 length = 4
B = {1, 0, 1, 1}
C = 1 1 0  0  0



C = length = 5 {
    for (int i = n; i > 0; i--)
    {
        if A[i] + B[i] > 1
            C[i] = 0
            carry_over = yes
    }
}