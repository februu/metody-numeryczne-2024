#include <iostream>
#include <vector>

#include "horner.h"
#include "interpolation.h"
#include "gauss.h"
#include "lu.h"

using std::cout;

int main()
{
    double **a = new double *[3];
    for (int i = 0; i < 3; ++i)
        a[i] = new double[3];

    double **b = new double *[3];
    for (int i = 0; i < 3; ++i)
        b[i] = new double[3];

    double a_data[3][3] = {{60.0, 30.0, 20.0}, {30.0, 20.0, 15.0}, {20.0, 15.0, 12.0}};
    double b_data[3][3] = {{3.0, 0.0, 1.0}, {0.0, -1.0, 3.0}, {1.0, 3.0, 0.0}};

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            a[i][j] = a_data[i][j];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            b[i][j] = b_data[i][j];

    doolittleLU(a, 3);
    doolittleLU(b, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }

    cout << "\n=======================\n\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << b[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}