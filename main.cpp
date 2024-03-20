#include <iostream>

#include "horner.h"
#include "interpolation.h"

using std::cout;

int main()
{
    double wsp[] = {1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0};

    cout << "w1(-4) = " << horner(-4.0, wsp, 4) << "\n";
    cout << "w1(-1) = " << horner(-1.0, wsp, 4) << "\n";

    double b[] = {-4.0, -1.0, 0.0};
    double a[] = {-4.0, 5.0 / 3.0, -7.0 / 6.0, 1.0 / 2.0};

    cout << "w2(0) = " << hornerNewton(-4.0, a, b, 4) << "\n";
    cout << "w2(2) = " << hornerNewton(-1.0, a, b, 4) << "\n";

    return 0;
}
