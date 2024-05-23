#include <iostream>
#include <cmath>

#include "horner.h"
#include "interpolation.h"
#include "gauss.h"
#include "lu.h"
#include "quad.h"
#include "gaussQuad.h"
#include "gramschmidt.h"

using std::cout;

int main()
{

    double x[] = {1, 1, 1, 1};

    gramschmidt(x, 4);

    return 0;
}