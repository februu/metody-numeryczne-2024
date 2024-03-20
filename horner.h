#pragma once
#include <cmath>

double horner(double x, const double *wsp, int size)
{
    if (size == 1)
        return wsp[0];
    else
        return horner(x, wsp, size - 1) * x + wsp[size - 1];
}

double hornerNewton(double x, const double *a, const double *b, int size, int step = 0)
{
    if (step == size - 2)
        return a[step];
    else
        return hornerNewton(x, a, b, size, step++) * (x - b[step]) + a[step];
}