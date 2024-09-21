#include <iostream>

#include <cstdlib>
#include <ctime>

#include <array>

const int ARR_SIZE = 32;

int a0[ARR_SIZE];
int a1[ARR_SIZE];
int a2[ARR_SIZE];

int main(int, char**) {
    srand(time(nullptr));

    for (int i = 0;i < ARR_SIZE;i++)
    {
        a0[i] = a1[i] = a2[i] = rand();
    }

    qsort(a1, ARR_SIZE, sizeof(int), [](const void* x, const void* y) {return *(int*)x - *(int*)y;});

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

    return 0;
}
