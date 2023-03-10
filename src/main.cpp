#include <iostream>
#include "comparason/branched.h"
#include "comparason/branchless.h"

int main(void)
{
    auto bched = branched::FooDerivate();
    auto bless = branchless::FooDerivate<branchless::Type1>();

    std::cout << "Branched processing started...\n";
    bched.process(100, true);
    std::cout << "Branchless processing started...\n";
    bless.process(100);

    return 0;
}