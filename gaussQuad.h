#include <cmath>
#include <iostream>

#include "horner.h"

double gaussQuad2(double (*f)(double x), double a, double b, int n)
{

    double x[] = {0.57735, 0.57735};
    double w[] = {1, 1};

    double result = 0.0;
    double interval = (b - a) / n;
    for (int k = 0; k < n; k++)
    {
        double newA = a + k * interval;
        double newB = newA + interval;
        double sum = 0.0;
        for (int i = 0; i < 2; i++)
            sum += w[i] * f((newB - newA) / 2 * x[i] + (newB + newA) / 2);
        result += (newB - newA) / 2 * sum;
    }

    return result;
}
double gaussQuad3(double (*f)(double x), double a, double b, int n)
{

    double x[] = {-0.774597, 0, 0.774597};
    double w[] = {5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0};

    double result = 0.0;
    double interval = (b - a) / n;
    for (int k = 0; k < n; k++)
    {
        double newA = a + k * interval;
        double newB = newA + interval;
        double sum = 0.0;
        for (int i = 0; i < 3; i++)
            sum += w[i] * f((newB - newA) / 2 * x[i] + (newB + newA) / 2);
        result += (newB - newA) / 2 * sum;
    }

    return result;
}
double gaussQuad4(double (*f)(double x), double a, double b, int n)
{

    double x[] = {-0.339981, 0.339981, -0.861136, 0.861136};
    double w[] = {0.652145, 0.652145, 0.347855, 0.347855};

    double result = 0.0;
    double interval = (b - a) / n;
    for (int k = 0; k < n; k++)
    {
        double newA = a + k * interval;
        double newB = newA + interval;
        double sum = 0.0;
        for (int i = 0; i < 4; i++)
            sum += w[i] * f((newB - newA) / 2 * x[i] + (newB + newA) / 2);
        result += (newB - newA) / 2 * sum;
    }

    return result;
}

double gaussQuad5(double (*f)(double x), double a, double b, int n)
{

    double x[] = {0, 0.538469, -0.538469, 0.90618, -0.90618};
    double w[] = {0.568889, 0.478629, 0.478629, 0.236927, 0.236927};

    double result = 0.0;
    double interval = (b - a) / n;
    for (int k = 0; k < n; k++)
    {
        double newA = a + k * interval;
        double newB = newA + interval;
        double sum = 0.0;
        for (int i = 0; i < 5; i++)
            sum += w[i] * f((newB - newA) / 2 * x[i] + (newB + newA) / 2);
        result += (newB - newA) / 2 * sum;
    }

    return result;
}

double gaussQuad5(double *w1, double *w2, double a, double b, int N, int n)
{
    double x[] = {0, 0.538469, -0.538469, 0.90618, -0.90618};
    double w[] = {0.568889, 0.478629, 0.478629, 0.236927, 0.236927};

    double result = 0.0;
    double interval = (b - a) / n;
    for (int k = 0; k < n; k++)
    {
        double newA = a + k * interval;
        double newB = newA + interval;
        double sum = 0.0;
        for (int i = 0; i < 5; i++)
        {
            double currentX = (newB - newA) * x[i] / 2 + (newB + newA) / 2;
            sum += w[i] * horner(currentX, w1, N) * horner(currentX, w2, N);
        }
        result += (newB - newA) / 2 * sum;
    }

    return result;
}
