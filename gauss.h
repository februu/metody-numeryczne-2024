// #pragma once
// #include <cmath>
// #include <iostream>

// double *gaussElimination(double **a, double *b, size_t n)
// {

//     double *x = new double[n];

//     // Crout
//     int *w = new int[n + 1];
//     for (int i = 0; i < n + 1; i++)
//         w[i] = i;

//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j <= n; j++)
//     //     {
//     //         if (w[j] == n)
//     //         {
//     //             std::cout << b[i] << "\t";
//     //         }
//     //         else
//     //         {
//     //             std::cout << a[i][w[j]] << "\t";
//     //         }
//     //     }
//     //     std::cout << "\n";
//     // }

//     // for (int i = 0; i < n + 1; i++)
//     //     cout << w[i] << " ";
//     // cout << "\n\n";

//     // Gauss elimination
//     for (int i = 0; i < n - 1; i++)
//     {
//         croutSwapColumnsInRow(a, b, n, i, w);

//         for (int k = i + 1; k < n; k++)
//         {
//             double tmp = a[k][i] / a[i][i];
//             for (int j = 0; j < n; j++)
//                 a[k][j] = a[k][j] - tmp * a[i][j];
//             b[k] = b[k] - tmp * b[i];
//         }
//     }

//     // Solve for xn
//     for (int i = n - 1; i >= 0; i--)
//     {
//         double sum = 0;
//         for (int j = i + 1; j < n; j++)
//             sum += a[i][j] * x[j];
//         x[i] = (b[i] - sum) / a[i][i];
//     }

//     delete[] w;
//     return x;
// }

// void croutSwapColumnsInRow(double **a, double *b, size_t n, int i, int *w)
// {
//     double maxAbs = std::abs(a[i][0]);
//     int maxIndex = 0;

//     for (int j = 1; j < n; j++)
//     {
//         if (std::abs(a[i][j]) > maxAbs)
//         {
//             maxAbs = std::abs(a[i][j]);
//             maxIndex = j;
//         }
//     }
//     if (std::abs(b[i]) > maxAbs)
//     {
//         maxAbs = std::abs(b[i]);
//         maxIndex = n;
//     }

//     // Find column to swap
//     int columnToSwapIndex;
//     for (columnToSwapIndex = 0; columnToSwapIndex < n + 1; columnToSwapIndex++)
//         if (w[columnToSwapIndex] == maxIndex)
//             break;

//     std::swap(w[i], w[columnToSwapIndex]);
// }

#pragma once
#include <cmath>
#include <iostream>

double *gaussElimination(double **a, double *b, size_t n)
{

    double *x = new double[n];
    for (int i = 0; i < n; i++)
        x[i] = 0.0;

    int *w = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        w[i] = i;

    // Gauss elimination
    for (int i = 0; i < n - 1; i++)
    {

        // Crout

        int k = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(a[i][w[k]]) < fabs(a[i][w[j]]))
                k = j;
        std::swap(w[k], w[i]);

        // ====

        for (int k = i + 1; k < n; k++)
        {
            double tmp;
            if (w[i] != n)
                tmp = a[k][w[i]] / a[i][w[i]];
            else
                tmp = b[k] / b[i];

            for (int j = i + 1; j <= n; j++)
                if (w[j] != n)
                    a[k][w[j]] -= tmp * a[i][w[j]];
                else
                    b[k] -= tmp * b[i];
        }
    }

    // Solve for xn
    for (int i = n - 1; i >= 0; i--)
    {
        double s = b[i];
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (w[j] != n)
                s -= a[i][w[j]] * x[w[j]];
            else
                s -= b[i] * x[w[j]];
        }

        if (w[i] != n)
            x[w[i]] = s / a[i][w[i]];
        else
            x[w[i]] = s / b[i];
    }

    delete[] w;
    return x;
}
