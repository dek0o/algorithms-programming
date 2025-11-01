#include "functions.h"

int main(){

    // Задание 2
    int ar[SIZE_1N][SIZE_1M] = {{1, 2, 3}, {4, 5, 6}};
    printf("Минимальное в двумерном массиве: %d\n", findMin(ar, SIZE_1N, SIZE_1M));

    int **dyn = malloc(SIZE_1N * sizeof(int*));
    for (int i = 0; i < 2; i++) dyn[i] = malloc(3 * sizeof(int));
    dyn[0][0] = 7; dyn[0][1] = 8; dyn[0][2] = 9;
    dyn[1][0] = 10; dyn[1][1] = 11; dyn[1][2] = 12;
    printf("Минимальное в динамическом двумерном массиве: %d\n", findMinDynamic(dyn, SIZE_1N, SIZE_1M));
    for (int i = 0; i < SIZE_1N; i++) free(dyn[i]);
    free(dyn);

    // Задание 3
    printf("abc и abd в myStrCmp: %d\n", myStrCmp("abc", "abd"));
    printf("abc и abc в myStrCmp: %d\n", myStrCmp("abc", "abc"));
    printf("abd и abc в myStrCmp: %d\n", myStrCmp("abd", "abc"));

    // Задание 4
    int *arr = malloc(3 * sizeof(int));
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    int size = 3;
    printf("Добавление уникального числа в массив:\n");
    printArray(arr, size);
    addUnique(&arr, &size, 4);
    printArray(arr, size);
    addUnique(&arr, &size, 2); // не должно добавиться
    printArray(arr, size);
    free(arr);

    // Задание 5
    printf("Сумма первых 5: %d\n", toSum(5));
    printf("6 число в ряду Фибоначчи: %d\n", findFibonacci(6));

    // Задание 6а
    int args[] = {5, 11, 4, 7, -1};
    updatedVarArgs(args[0], 0);
    updatedVarArgs(args[0], args[1], 0);
    updatedVarArgs(args[0], args[1], args[2], args[3], args[4], 0);

    // Задание 6б
    printf("Сумма, используя va: %d\n", sum_va(3, 1, 2, 3));

    // Задание 7
    int arr7[] = {3, 1, 4, 1, 5};
    *myMin(arr7, 5) = 0;
    printf("Массив после вставки 0 вместо минимального: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr7[i]);
    printf("\n");

    return 0;
}
