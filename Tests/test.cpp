#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <memory>
#include <string>
#include "comparason/branched.h"
#include "comparason/branchless.h"


TEST_CASE("BRANCHED VS BRANCLESS")
{
    // Variables instantiation.
    std::unique_ptr<branched::FooBase> bched = std::make_unique<branched::FooDerivate>();
    std::unique_ptr<branchless::FooBase> bless = std::make_unique<branchless::FooDerivate<branchless::Type1>>();

    size_t round1 = 10;
    size_t round2 = 100;
    size_t round3 = 1000;
    size_t round4 = 10000;
    size_t round5 = 100000;
    size_t round6 = 1000000;
    size_t round7 = 10000000;
    size_t round8 = 100000000;

    // Round 1
    BENCHMARK("Branched code round 1: 10^1 iterations") {
        return bched->process(round1, true);
    };

    BENCHMARK("Branchless code round 1: 10^1 iterations") {
        return bless->process(round1);
    };

    // Round 2
    BENCHMARK("Branched code round 2: 10^2 iterations") {
        return bched->process(round2, true);
    };

    BENCHMARK("Branchless code round 2: 10^2 iterations") {
        return bless->process(round2);
    };

    // Round 3
    BENCHMARK("Branched code round 3: 10^3 iterations") {
        return bched->process(round3, true);
    };

    BENCHMARK("Branchless code round 3: 10^3 iterations") {
        return bless->process(round3);
    };

    // Round 4
    BENCHMARK("Branched code round 4: 10^4 iterations") {
        return bched->process(round3, true);
    };

    BENCHMARK("Branchless code round 4: 10^4 iterations") {
        return bless->process(round3);
    };

    // Round 5
    BENCHMARK("Branched code round 5: 10^5 iterations") {
        return bched->process(round1, true);
    };

    BENCHMARK("Branchless code round 5: 10^5 iterations") {
        return bless->process(round5);
    };

    // Round 2
    BENCHMARK("Branched code round 6: 10^6 iterations") {
        return bched->process(round6, true);
    };

    BENCHMARK("Branchless code round 6: 10^6 iterations") {
        return bless->process(round2);
    };

    // Round 7
    BENCHMARK("Branched code round 7: 10^7 iterations") {
        return bched->process(round7, true);
    };

    BENCHMARK("Branchless code round 7: 10^7 iterations") {
        return bless->process(round7);
    };

    // Round 4
    BENCHMARK("Branched code round 8: 10^8 iterations") {
        return bched->process(round8, true);
    };

    BENCHMARK("Branchless code round 8: 10^8 iterations") {
        return bless->process(round8);
    };
}