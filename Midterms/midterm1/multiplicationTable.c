#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    printf("Enter size of table: ");
    int size;
    scanf("%d",&size);

    int *table = (int *)malloc(size*size*sizeof(int));

    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            *(table + i*size + j) = (i+1)*(j+1);
        }
    }
    for(int i=0; i<size; ++i) 
    {
        for (int j = 0; j < size; ++j)
        {
            printf("%d ", *(table + i*size + j));
        }
        printf("\n");
    }


    return 0;
}