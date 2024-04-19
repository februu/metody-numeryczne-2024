#include <iostream>
#include <cmath>

#include "horner.h"
#include "interpolation.h"
#include "gauss.h"
#include "lu.h"
#include "quad.h"
#include "gaussQuad.h"

using std::cout;

double fa(double x)
{
    return x * x * pow(sin(x), 3);
    // 0 -> 4.5
    // -4,402577
}

double fb(double x)
{
    return (x - 1) * exp(x * x);
    // -2 -> 2
}

double fc(double x)
{
    if (x == 0.0)
        return 1.0;
    return sin(x) / x;
    // 0 -> 1
}

double fd(double x)
{
    return sin(1 / x);
    // 10e-8 -> 1
}

// sorawdzuc dla 10 od -2 do -6
int main()
{
    cout << "Test:\n";
    cout << gaussQuad2(fa, 0, 4.5, 256) << "\n";
    cout << gaussQuad3(fa, 0, 4.5, 256) << "\n";
    cout << gaussQuad4(fa, 0, 4.5, 256) << "\n";
    cout << gaussQuad5(fa, 0, 4.5, 256) << "\n";

    double w1[] = {-2.0, 1.0, 2.0, 1.0};
    double w2[] = {10.0, -1.0, 1.0, 2.0};

    cout << horner(0, w1, 4) << "\n";
    cout << gaussQuad5(w1, w2, -2, 2, 4, 256);
    return 0;
}