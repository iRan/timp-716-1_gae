#include <stdio.h>
#include <stdlib.h>

void sort(int *array, int size)
{
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++)
        {
            tmp = array[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < array[j - step])
                    array[j] = array[j - step];
                else
                    break;
            }
            array[j] = tmp;
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

