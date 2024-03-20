#pragma once
#include <cmath>

struct Point
{
    double x, y;
};

double lagrange_interpolation(const Point *points, size_t n, double x)
{
    double result = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        double term = points[i].y;
        for (size_t j = 0; j < n; j++)
            if (j != i)
                term *= (x - points[j].x) / (points[i].x - points[j].x);
        result += term;
    }
    return result;
}