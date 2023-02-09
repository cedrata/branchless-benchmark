#include "./branched.h"

namespace branched
{
    void procBranched1()
    {
        int a = 1;
        int b = a;
    }

    void procBranched2()
    {
        int a = 1;
        int b = a;
    }

    void FooDerivate::process(bool type)
    {
        if (type)
            procBranched1();
        else
            procBranched2();
    }
} // namespace branched