#include <iostream>

#include <cstdlib>
#include <ctime>

#include <array>

const int ARR_SIZE = 64;

int a0[ARR_SIZE];
int a1[ARR_SIZE];
int a2[ARR_SIZE];

void BubbleSort(int arr[], int len)
{
    for (int i = 0;i < len;i++)
    {
        for (int j = 0;j < len - i - 1;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SelSort(int arr[], int len)
{
    for (int i = 0;i < len;i++)
    {
        int minIdx = i;
        int idxVal = arr[minIdx];
        for (int j = i + 1;j < len;j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
                idxVal = arr[j];
            }
        }

        if (minIdx != i)
        {
            arr[minIdx] = arr[i];
            arr[i] = idxVal;
        }
    }
}

void InsertSort(int arr[], int len)
{
    for (int i = 1;i < len;i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            int j;
            for (j = i - 1;(j >= 0) && (arr[j] > temp);j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

int main(int, char**) {
    srand(time(nullptr));

    for (int i = 0;i < ARR_SIZE;i++)
    {
        a0[i] = a1[i] = a2[i] = rand();
    }

    qsort(a1, ARR_SIZE, sizeof(int), [](const void* x, const void* y) {return *(int*)x - *(int*)y;});

    // test
    InsertSort(a2, ARR_SIZE);

    bool isNeq = false;

    for (int i = 0;i < ARR_SIZE;i++)
    {
        printf("%8d\t%8d\t%8d\n", a0[i], a1[i], a2[i]);

        if (a1[i] != a2[i])
        {
            isNeq = true;
        }
    }

    if (isNeq)
    {
        printf("---------------failed!!--------------\n");
    }
    else
    {
        printf("---------------pass!!--------------\n");
    }

    return 0;
}
