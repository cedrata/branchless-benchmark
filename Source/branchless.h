#include <iostream>

struct Type1 {};
struct Type2 {};

template<typename SomeType>


class BranchlessBase
{
    BranchlessBase() {}

    virtual ~BranchlessBase() = default;

    virtual void process() = 0;
};

template<typename SomeType>
class BranchlessDerivate
{
    ~BranchlessDerivate() {}

    void process()
    {

    }
};