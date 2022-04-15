#include "example.h"

// Here we implement the function using C++ code, but since it's
// declaration has to be compatible with C everything goes in extern "C" scope.
int add(int a, int b)
{
    // Prove we have (at least) C++11 features.
    const auto sum = [&]() { return a + b; } ();
    return sum;
}

