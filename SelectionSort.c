#include <stdio.h>

int main()
{
    int arr[5] = {9, 6, 8, 2, 5};
    int size = 5;
    printf("Before Sort = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }

    for (int j = 0; j < size - 1; j++)
    {
        int pos;
        for (int i = j + 1; i < size; i++)
        {
            pos = 0;
            if (arr[pos] > arr[i])
            {
                pos = i;
            }
        }

        if(pos != j)
        {
            int temp = arr[j];
            arr[j] = arr[pos];
            arr[pos] = temp;
        }
    }

    printf("\nAfter Sort = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}