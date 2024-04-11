#include <cmath>
#include <iostream>

double quad_t(double (*f)(double x), double a, double b, double h)
{
    double sum = 0.0;
    int maxIterations = (b - a) / h;
    for (int i = 0; i < maxIterations; i++)
    {
        double x1 = f(a + i * h);
        double x2 = f(a + (i + 1) * h);
        sum += x1 + x2;
    }

    return sum / 2 * h;
}

double quad_s(double (*f)(double x), double a, double b, double h)
{
    double sum = 0.0;
    int maxIterations = (b - a) / h;
    for (int i = 0; i < maxIterations; i++)
    {
        double x1 = f(a + i * h);
        double x2 = f(a + (i + 1) * h);
        double xm = f((a + i * h + a + (i + 1) * h) / 2.0);
        sum += x1 + x2 + 4 * xm;
    }

    return sum / 6 * h;
}