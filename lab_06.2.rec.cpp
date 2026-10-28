// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів рекурсивним способом
// Варіант 1
 
#include <iostream>
#include <iomanip>
#include <time.h>
 
using namespace std;
 
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High-Low+1);
    if (i<size-1)
        Create(a, size, Low, High, i+1);
}
 
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i<size-1)
        Print(a, size, i+1);
    else
        cout << endl;
}
 
int IndexMax(int* a, const int size, int i, int imax)
{
    if (a[i]>a[imax])
        imax=i;
    if (i<size-1)
        return IndexMax(a, size, i+1, imax);
    else
        return imax;
}
 
int IndexMin(int* a, const int size, int i, int imin)
{
    if (a[i]<a[imin])
        imin=i;
    if (i<size-1)
        return IndexMin(a, size, i+1, imin);
    else
        return imin;
}
 
void SwapMaxMin(int* a, const int size)
{
    int imax = IndexMax(a, size, 1, 0);     // перший елемент вважаємо максимальним
    int imin = IndexMin(a, size, 1, 0);     // перший елемент вважаємо мінімальним
 
    int tmp = a[imax];                      // обмін місцями максимального
    a[imax] = a[imin];                      // та мінімального елементів
    a[imin] = tmp;
}
 
int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел
 
    const int n=20;
    int a[n];
 
    int Low = -20;
    int High = 50;
 
    Create(a, n, Low, High, 0);
    Print(a, n, 0);
 
    SwapMaxMin(a, n);
    Print(a, n, 0);
 
    return 0;
}
 