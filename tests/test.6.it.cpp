#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <iomanip>
#include <time.h>

#define main program_main
#include "../lab_06.1.it.cpp"
#undef main

TEST_CASE("Count і Sum на відомому масиві")
{
    int a[20] = { 25, 16, 20, 39, -3, -8, 3, 45, 7, 28,
                  44, -13, 34, 7, 2, 20, -12, 25, -14, -9 };

    CHECK(Count(a, 20, 0) == 11);
    CHECK(Sum(a, 20, 0) == 226);
}

TEST_CASE("Zero обнуляє лише додатні з індексами не кратними 5")
{
    int a[20] = { 25, 16, 20, 39, -3, -8, 3, 45, 7, 28,
                  44, -13, 34, 7, 2, 20, -12, 25, -14, -9 };
    int expected[20] = { 25, 0, 0, 0, -3, -8, 0, 0, 0, 0,
                         44, -13, 0, 0, 0, 20, -12, 0, -14, -9 };

    Zero(a, 20, 0);

    for (int i = 0; i < 20; i++)
    {
        CAPTURE(i);
        CHECK(a[i] == expected[i]);
    }
    CHECK(Count(a, 20, 0) == 0);   // після обнулення підходящих елементів не лишилось
}

TEST_CASE("Немає додатних елементів")
{
    int a[5] = { -1, -2, -3, -4, -5 };

    CHECK(Count(a, 5, 0) == 0);
    CHECK(Sum(a, 5, 0) == 0);
}

TEST_CASE("Create заповнює масив значеннями з діапазону")
{
    int a[20];
    Create(a, 20, -20, 50, 0);

    for (int i = 0; i < 20; i++)
    {
        CAPTURE(i);
        CHECK(a[i] >= -20);
        CHECK(a[i] <= 50);
    }
}
