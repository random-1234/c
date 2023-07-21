#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }

    free(temp);
}

void mergeSort(int arr[], int low, int high)
{
    if (low == high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int a[] = {2, 3, 1, 4, 5, 6, 9, 8, 92, 91};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    clock_t start = clock();
    mergeSort(a, 0, n - 1);
    clock_t end = clock();

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime: %f seconds\n", duration);

    return 0;
}
