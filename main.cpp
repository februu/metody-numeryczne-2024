#include <iostream>
#include <cmath>

#include "horner.h"
#include "interpolation.h"
#include "gauss.h"
#include "lu.h"
#include "quad.h"

using std::cout;

double fa(double x)
{
    return x * x * pow(sin(x), 3);
    // 0 -> 4.5
    // -4,402577
}

double fb(double x)
{
    return (x - 1) * exp(x * x);
    // -2 -> 2
}

double fc(double x)
{
    if (x == 0.0)
        return 1.0;
    return sin(x) / x;
    // 0 -> 1
}

double fd(double x)
{
    return sin(1 / x);
    // 10e-8 -> 1
}

// sorawdzuc dla 10 od -2 do -6
int main()
{
    cout << "Funkcja 1:\n";
    for (int i = 0; i > -5; i--)
        cout << pow(10, (i - 2)) << "\t\t" << quad_t(fa, 0, 4.5, pow(10, (i - 2))) << "\t" << quad_s(fa, 0, 4.5, pow(10, (i - 2))) << "\n";
    cout << "\nFunkcja 2:\n";
    for (int i = 0; i > -5; i--)
        cout << pow(10, (i - 2)) << "\t\t" << quad_t(fb, -2, 2, pow(10, (i - 2))) << "\t" << quad_s(fb, -2, 2, pow(10, (i - 2))) << "\n";
    cout << "\nFunkcja 3:\n";
    for (int i = 0; i > -5; i--)
        cout << pow(10, (i - 2)) << "\t\t" << quad_t(fc, 0, 1, pow(10, (i - 2))) << "\t" << quad_s(fc, 0, 1, pow(10, (i - 2))) << "\n";
    cout << "\nFunkcja 4:\n";
    for (int i = 0; i > -5; i--)
        cout << pow(10, (i - 2)) << "\t\t" << quad_t(fd, pow(10, -4), 1, pow(10, (i - 2))) << "\t" << quad_s(fd, pow(10, -4), 1, pow(10, (i - 2))) << "\n";

    return 0;
}