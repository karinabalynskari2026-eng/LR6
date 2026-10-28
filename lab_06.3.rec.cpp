// Лабораторна робота № 6.3
// Варіант 1
// Рекурсивний спосіб
 
#include <iostream>
 
using namespace std;
 
int SumOfSquares(int* a, const int size, int i);
 
template <typename T>
T SumOfSquares(T* a, const int size, int i);
 
int main()
{
    const int n = 10;
 
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int s1 = SumOfSquares(a, n, 0);
    cout << "SumOfSquares(a, n) = " << s1 << endl;
 
    int s2 = SumOfSquares<int>(a, n, 0);
    cout << "SumOfSquares<int>(a, n) = " << s2 << endl;
 
    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    double s3 = SumOfSquares<double>(b, n, 0);
    cout << "SumOfSquares<double>(b, n) = " << s3 << endl;
 
    return 0;
}
 
int SumOfSquares(int* a, const int size, int i)
{
    if (i < size)
        return a[i] * a[i] + SumOfSquares(a, size, i + 1);
    else
        return 0;
}
 
template <typename T>
T SumOfSquares(T* a, const int size, int i)
{
    if (i < size)
        return a[i] * a[i] + SumOfSquares<T>(a, size, i + 1);
    else
        return T();
}