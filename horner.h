#pragma once
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

double horner(double x, const double *wsp, int size)
{
    if (size == 1)
        return wsp[0];
    else
        return horner(x, wsp, size - 1) * x + wsp[size - 1];
}

double hornerNewton(double x, const double *a, const double *b, int size)
{
    double suma = 0.0;
    for (int i = 0; i < size; i++)
    {

        if (i == 0)
        {
            suma += a[0];
            continue;
        }

        double tmp = a[i];
        for (int j = 0; j < i; j++)
            tmp *= x - b[j];

        suma += tmp;
    }
    return suma;
}

#include <vector>

std::vector<double> standardPolynomial(const std::vector<double> &a, const std::vector<double> &b)
{
    int N = b.size();
    std::vector<double> result(N, 0.0); // result[j] holds coefficient of x^j in final sum
    std::vector<double> p(N), prev(N);  // At the ith step, p[ ] is the ith polynomial of Newton factors

    p[0] = 1;
    result[0] = a[0] * p[0];
    for (int i = 1; i < N; i++)
    {
        prev = p;
        p[0] = -b[i - 1] * prev[0];
        result[0] += a[i] * p[0];
        for (int j = 1; j <= i; j++)
        {
            p[j] = prev[j - 1] - b[i - 1] * prev[j];
            result[j] += a[i] * p[j];
        }
    }

    return result;
}
