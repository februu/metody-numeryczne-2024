#include <cmath>
#include <iostream>

using std::cout;

void doolittleLU(double **a, size_t n)
{
    int *w = new int[n];
    for (int i = 0; i < n; i++)
        w[i] = i;

    // LU
    for (int j = 0; j < n; j++)
    {

        // Swap rows
        int p = j;
        for (int i = j + 1; i < n; i++)
            if (fabs(a[w[i]][j]) > fabs(a[w[p]][j]))
                p = i;
        std::swap(w[p], w[j]);

        for (int i = 0; i < n; i++)
        {
            double sum = 0.0;
            if (i <= j)
            {
                // Upper
                for (int k = 0; k < i; k++)
                    sum += a[w[i]][k] * a[w[k]][j];
                a[w[i]][j] -= sum;
            }
            else
            {
                // Lower
                for (int k = 0; k < j; k++)
                    sum += a[w[i]][k] * a[w[k]][j];
                a[w[i]][j] = (a[w[i]][j] - sum) / a[w[j]][j];
            }
        }
    }

    delete[] w;
}
