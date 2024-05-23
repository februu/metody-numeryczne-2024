#pragma once

#include <vector>
#include <cmath>
#include <iostream>

#include "gaussQuad.h"

void gramschmidt(double *x, int n)
{
    // Macierz F
    double **f = new double *[n];
    for (int i = 0; i < n; ++i)
        f[i] = new double[n];

    // Macierz G
    double **g = new double *[n];
    for (int i = 0; i < n; ++i)
        g[i] = new double[n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            f[i][j] = 0.0;
            g[i][j] = 0.0;
            if (i == j)
                f[i][j] = x[i];
        }

    // Gram-Schmidt
    for (int i = 0; i < n; ++i)
        g[0][i] = f[0][i];

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            g[i][j] = f[i][j];

        for (int j = 0; j < i; ++j)
            for (int k = 0; k < n; ++k)
                g[i][k] -= (gaussQuad5(f[i], g[j], 0.0, 1.0, n, n) / gaussQuad5(g[j], g[j], 0.0, 1.0, n, n)) * g[j][k];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << g[i][j] << " ";
        std::cout << std::endl;
    }
}