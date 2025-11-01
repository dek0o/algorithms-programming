#include <stdio.h>

int fibonachiRecursion(int, int, int, int);
void fibonachiProsto(int);
void printTriangleRecursion(int, int);
void printTriangleProsto(int);
void MergeSort(int*, int, int); //Сложность O(nlog(n))

int main()
{
    printf("Фибоначчи рекурсией:\n");
    fibonachiRecursion(10, 1, 0, 1);
    printf("Фибоначчи циклом:\n");
    fibonachiProsto(10);
    printf("Равнобедренный треугольник рекурсией:\n");
    printTriangleRecursion(7, 0);
    printf("Равнобедренный треугольник циклом:\n");
    printTriangleProsto(7);
    printf("Сортировка массива слиянием:\n");
    int a[] = {1, 5, 2, 7, 3, 3, 3, 9};
    int size = sizeof(a) / sizeof(a[0]);
    MergeSort(a, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int fibonachiRecursion(int n, int cnt, int lstlst, int lst)
{
    printf("%d\n", lstlst);
    if (n == cnt)
    {
        return lst;
    }
    else
    {
        int t = lst + lstlst;
        lstlst = lst;
        lst = t;
        cnt++;
    }

    return fibonachiRecursion(n, cnt, lstlst, lst);
}

void fibonachiProsto(int n)
{
    int lstlst = 0, lst = 1, cnt = 1;
    while (cnt <= n)
    {
        printf("%d\n", lstlst);
        int t = lst + lstlst;
        lstlst = lst;
        lst = t;
        cnt++;
    }
}

void printTriangleRecursion(int n, int cnt)
{
    if (n <= 0) return;
    
    for (int i = 0; i < cnt; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < n; i++)
    {
        printf("=");
    }
    printf("\n");

    printTriangleRecursion(n - 2, cnt + 1);
}

void printTriangleProsto(int n)
{
    int cnt = 0;
    for (int i = n; i >= 0; i -= 2)
    {
        for (int j = 0; j < cnt; j++)
            printf(" ");
        for (int j = 0; j < i; j++)
            printf("=");
        printf("\n");
        cnt++;
    }
}

void merge(int* array, int left, int mid, int right)
{
    // Пример: слияние [1,2,5,7] и [3,3,3,9] в финальном массиве
    // Вычисляем размеры двух подмассивов
    int n1 = mid - left + 1; // n1 = 4 (левая половина)
    int n2 = right - mid;    // n2 = 4 (правая половина)

    // Создаем временные массивы
    int L[n1], R[n2]; 

    // Копируем данные в временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];
    // L = [1,2,5,7], R = [3,3,3,9]

    int i = 0, j = 0, k = left; // указатель L, указатель R , позиция в array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int* array, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}
