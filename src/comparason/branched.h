#pragma once

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

    class FooBase
    {
    public:
        FooBase() {}

        virtual ~FooBase() = default;

        virtual void process(size_t iterations, bool type) = 0;
    };

    class FooDerivate : public FooBase
    {
    public:
        FooDerivate() {}
        ~FooDerivate() override {}

        void process(size_t iterations, bool type) override
        {
            for (int i = 0; i < iterations; ++i)
            {
                if (type)
                    procBranched1();
                else
                    procBranched2();
            }
        }
    };

} // namespace branched;