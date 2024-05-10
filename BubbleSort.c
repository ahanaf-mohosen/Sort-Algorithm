// 6) Write a program in C to sort elements of an array in ascending order.

#include <stdio.h>

#define MAX_SIZE 100

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swap elements if they are in the wrong order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int array[MAX_SIZE], size;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, size);

    printf("\nArray in ascending order: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
