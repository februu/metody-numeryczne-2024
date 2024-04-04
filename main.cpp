#include <iostream>
#include <vector>

#include "horner.h"
#include "interpolation.h"
#include "gauss.h"

using std::cout;
using std::vector;

int main()
{

    double **a = new double *[5];
    for (int i = 0; i < 5; ++i)
    {
        a[i] = new double[5];
    }

    double data[5][5] = {
        {1.0, -3.0, 4.0, 6.8, 9.0},
        {-3.0, 2.0, 4.6, 6.3, -10.0},
        {2.0, -1.0, 2.8, -8.4, -5.0},
        {-6.0, 2.0, 7.0, -0.5, -0.9},
        {5.0, -2.0, -0.5, 12.0, -4.0}};

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            a[i][j] = data[i][j];
        }
    }

    double b[] = {74.64, -40.26, -2.32, 12.6, -8.9};

    double *gauss = gaussElimination(a, b, 5);

    for (int i = 0; i < 5; i++)
        cout << gauss[i] << "\n";

    return 0;
}