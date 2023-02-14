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

        virtual void process(bool type) = 0;
    };

    class FooDerivate : public FooBase
    {
    public:
        FooDerivate() {}
        ~FooDerivate() override {}

        void process(bool type) override
        {
            if (type)
                procBranched1();
            else
                procBranched2();
        }
    };

} // namespace branched;