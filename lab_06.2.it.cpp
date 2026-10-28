// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційним способом
// Варіант 1
 
#include <iostream>
#include <iomanip>
#include <time.h>
 
using namespace std;
 
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i=0; i<size; i++)
        a[i] = Low + rand() % (High-Low+1);
}
 
void Print(int* a, const int size)
{
    for (int i=0; i<size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}
 
int IndexMax(int* a, const int size)
{
    int max = a[0];                 // перший елемент вважаємо максимальним
    int imax = 0;                   // індекс максимального елемента
    for (int i=1; i<size; i++)
        if (a[i]>max)
        {
            max = a[i];
            imax = i;
        }
    return imax;
}
 
int IndexMin(int* a, const int size)
{
    int min = a[0];                 // перший елемент вважаємо мінімальним
    int imin = 0;                   // індекс мінімального елемента
    for (int i=1; i<size; i++)
        if (a[i]<min)
        {
            min = a[i];
            imin = i;
        }
    return imin;
}
 
void SwapMaxMin(int* a, const int size)
{
    int imax = IndexMax(a, size);
    int imin = IndexMin(a, size);
 
    int tmp = a[imax];              // обмін місцями максимального
    a[imax] = a[imin];              // та мінімального елементів
    a[imin] = tmp;
}
 
int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел
 
    const int n=20;
    int a[n];
 
    int Low = -20;
    int High = 50;
 
    Create(a, n, Low, High);
    Print(a, n);
 
    SwapMaxMin(a, n);
    Print(a, n);
 
    return 0;
}
 