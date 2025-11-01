#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

//константы для размерности массивов в первом задании
#define SIZE_1N 2
#define SIZE_1M 3

// Prototypes
void swap(int *i, int *j);
int findMin(int ar[][SIZE_1M], int rows, int cols);
int findMinDynamic(int **ar, int rows, int cols);
int myStrCmp(const char *s1, const char *s2);
void printArray(int *arr, int size);
int addUnique(int **arr, int *size, int value);
int toSum(int n);
int findFibonacci(int n);
void varArgs(int arg1, ...);
void updatedVarArgs(int arg1, ...);
int sum_va(int count, ...);
int *myMin(int *arr, int size);