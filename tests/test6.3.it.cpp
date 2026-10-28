#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

#define main program_main
#include "../lab_06.3.it.cpp"
#undef main

TEST_CASE("Звичайна функція: масив 1..10")
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    CHECK(SumOfSquares(a, 10) == 385);
}

TEST_CASE("Шаблон для int: масив 1..10")
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    CHECK(SumOfSquares<int>(a, 10) == 385);
}

TEST_CASE("Від'ємні числа та нулі")
{
    int a[3] = { -1, -2, 3 };
    int z[3] = { 0, 0, 0 };

    CHECK(SumOfSquares(a, 3) == 14);
    CHECK(SumOfSquares<int>(a, 3) == 14);
    CHECK(SumOfSquares(z, 3) == 0);
}

TEST_CASE("Один елемент і порожній масив")
{
    int a[1] = { 5 };

    CHECK(SumOfSquares(a, 1) == 25);
    CHECK(SumOfSquares(a, 0) == 0);
}

TEST_CASE("Шаблон для double")
{
    double b[3] = { 1.5, 2.0, 2.5 };
    double c[10] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    double d[2] = { -1.5, 1.5 };

    CHECK(SumOfSquares<double>(b, 3) == doctest::Approx(12.5));
    CHECK(SumOfSquares<double>(c, 10) == doctest::Approx(443.98));
    CHECK(SumOfSquares<double>(d, 2) == doctest::Approx(4.5));
}

TEST_CASE("Шаблон для long long: великі значення")
{
    long long c[2] = { 100000, 100000 };

    CHECK(SumOfSquares<long long>(c, 2) == 20000000000LL);
}