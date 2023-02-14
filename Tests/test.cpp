#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <memory>
#include "comparason/branched.h"
#include "comparason/branchless.h"


TEST_CASE("BRANCHED VS BRANCLESS")
{
    // Variables instantiation.
    std::unique_ptr<branched::FooBase> bched = std::make_unique<branched::FooDerivate>();
    std::unique_ptr<branchless::FooBase> bless = std::make_unique<branchless::FooDerivate<branchless::Type1>>();

    BENCHMARK("Branched code") {
        return bched->process(true);
    };

    BENCHMARK("Branchless code") {
        return bless->process();
    };
}