#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[(low + high) / 2];
        int i = low;
        int j = high;
        int temp;

        while (i <= j)
        {
            while (arr[i] < pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }

            if (i <= j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        if (low < j)
            quickSort(arr, low, j);
        if (i < high)
            quickSort(arr, i, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original Array: \n");
    printArray(array, n);

    quickSort(array, 0, n - 1);
    printf("Sorted with Middle Element as Pivot: \n");
    printArray(array, n);

    return 0;
}