#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <iomanip>
#include <time.h>

#define main program_main
#include "../lab_06.2.it.cpp"
#undef main

TEST_CASE("IndexMax та IndexMin повертають індекси")
{
    int a[5] = { 3, 9, -4, 7, 1 };

    CHECK(IndexMax(a, 5) == 1);
    CHECK(IndexMin(a, 5) == 2);
}

TEST_CASE("SwapMaxMin міняє місцями максимальний і мінімальний")
{
    int a[5] = { 3, 9, -4, 7, 1 };
    int expected[5] = { 3, -4, 9, 7, 1 };

    SwapMaxMin(a, 5);

    for (int i = 0; i < 5; i++)
    {
        CAPTURE(i);
        CHECK(a[i] == expected[i]);
    }
}

TEST_CASE("Максимальний на початку, мінімальний в кінці")
{
    int a[4] = { 10, 5, 3, -2 };
    int expected[4] = { -2, 5, 3, 10 };

    SwapMaxMin(a, 4);

    for (int i = 0; i < 4; i++)
    {
        CAPTURE(i);
        CHECK(a[i] == expected[i]);
    }
}

TEST_CASE("Кілька однакових максимумів: міняється перший")
{
    int a[5] = { 5, 9, 2, 9, -1 };
    int expected[5] = { 5, -1, 2, 9, 9 };

    SwapMaxMin(a, 5);

    for (int i = 0; i < 5; i++)
    {
        CAPTURE(i);
        CHECK(a[i] == expected[i]);
    }
}

TEST_CASE("Усі елементи однакові: масив не змінюється")
{
    int a[4] = { 7, 7, 7, 7 };

    SwapMaxMin(a, 4);

    for (int i = 0; i < 4; i++)
    {
        CAPTURE(i);
        CHECK(a[i] == 7);
    }
}

TEST_CASE("Один елемент і від'ємні числа")
{
    int a[1] = { 5 };
    SwapMaxMin(a, 1);
    CHECK(a[0] == 5);

    int b[3] = { -5, -9, -1 };
    SwapMaxMin(b, 3);
    CHECK(b[0] == -5);
    CHECK(b[1] == -1);
    CHECK(b[2] == -9);
}

TEST_CASE("Create заповнює масив значеннями з діапазону")
{
    int a[20];
    Create(a, 20, -20, 50);

    for (int i = 0; i < 20; i++)
    {
        CAPTURE(i);
        CHECK(a[i] >= -20);
        CHECK(a[i] <= 50);
    }
}