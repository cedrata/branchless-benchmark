#pragma once

namespace branched
{
    void procBranched1();

    void procBranched2();

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
        ~FooDerivate() {}

        void process(bool type) override;
    };

} // namespace branched;