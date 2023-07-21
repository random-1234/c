#include <stdio.h>
#include <time.h>

int partition(int arr[], int l, int h)
{
    int i = l - 1;
    int p = arr[h];
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = temp;
    return (i + 1);
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

int main()
{
    int arr[] = {8, 4, 7, 9, 3, 10, 5};
    clock_t start = clock();
    quickSort(arr, 0, 6);
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nTime : %f seconds\n", duration);
}