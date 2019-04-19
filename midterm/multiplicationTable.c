#include <stdio.h>

int main() {


    printf("Enter size of table: ");
    int size;
    scanf("%d",&size);

    int table[size][size];

    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            table[i][j] = (i+1)*(j+1);

    for(int i=0; i<size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%d ", table[i][j]);
        printf("\n");
    }


    return 0;
}