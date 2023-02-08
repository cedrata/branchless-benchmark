struct Type1 {};
struct Type2 {};

template<typename SomeType>


class FooBase
{
    FooBase() {}

    virtual ~FooBase() = default;
};

template<typename SomeType>
class FooDerivate1
{
    ~FooDerivate1() {}

    void process()
    {

    }
}