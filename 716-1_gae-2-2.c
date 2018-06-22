#include <stdio.h>

int main()
{
    unsigned int n;
    int x, count = 1;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", &x);
        if(x>=0){
            count = count*(x-i);
        }
    }
    printf("%d", count);
    return 0;
}

