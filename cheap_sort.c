#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// To heapify a subtree rooted with node i
void heapify(int arr[], int n, int i)
{

    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {

        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
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

    heapSort(arr, count);

    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Array: [");
    for (int i = 0; i < count-1; i++){
        printf("%i, ", arr[i]);
    }
    printf("%i", arr[count-1]);
    printf("]\nTime ran: %f", execution_time);
    return 0;

}
