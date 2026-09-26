#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(){

    int size;

    printf("Enter length of array: ");
    scanf("%d", &size);

    int arr[size];
    int count = 0;

    printf("Enter array: ");
    while (count < size){
        if (scanf("%d", &arr[count]) != 1)
            break;

        count++;

        if (count < size)
            scanf(" ,");
    }

    clock_t start_time = clock();

    qsort(arr, count, sizeof(int), compare);

    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Array: [");
    for (int i = 0; i < count-1; i++){
        printf("%i, ", arr[i]);
    }
    printf("%i", arr[count-1]);
    printf("]\nTime ran: %f\n", execution_time);
    return 0;

}
