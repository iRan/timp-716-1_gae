#include <stdio.h>
#include <stdlib.h>

void sort(int *array, int size)
{
    if (array && size)
    {
        int jump = size;
        int i;
        int swapped = 1;
        while (jump > 1 || swapped)
        {
            if (jump > 1)
                jump /= 1.24733;
            swapped = 0;
            for (i = 0; i + jump < size; ++i)
                if (array[i + jump] < array[i])
                {
                    int tmp;
                    tmp = array[i];
                    array[i] = array[i + jump];
                    array[i + jump] = tmp;
                    swapped = 1;
                }
        }
    }
}

int main()
{
    int n, i;


    scanf("%d", &n);

    int m[n];

    for(i=0; i<n; i++){
        scanf("%d", &m[i]);
    }
    sort(m, n);

    for (i = 0; i<n; i++){
        printf("%d ", m[i]);
    }
    printf("\n");
    return 0;
}

