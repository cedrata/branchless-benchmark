#pragma once

#include <type_traits>

namespace branchless
{
    struct Type1
    {
    };
    struct Type2
    {
    };

    template <typename SomeType, std::enable_if_t<std::is_same_v<SomeType, Type1>, bool> = true>
    void procBranchless()
    {
        int a = 1;
        int b = a;
    }

    template <typename SomeType, std::enable_if_t<std::is_same_v<SomeType, Type2>, bool> = true>
    void procBranchless()
    {
        int a = 1;
        int b = a;
    }

    class FooBase
    {
    public:
        FooBase() {}

        virtual ~FooBase() = default;

        virtual void process() = 0;
    };

    template <typename SomeType>
    class FooDerivate : public FooBase
    {
    public:
        FooDerivate() {}
        ~FooDerivate() override {}

        void process() override
        {
            for (int i = 0; i < 100000; ++i)
            {
                procBranchless<SomeType>();
            }
        }
    };

    
    template class FooDerivate<Type1>;
    template class FooDerivate<Type2>;
} // branchless