#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lang.h"

TEST_CASE()
{
    SECTION("Sentence tests")
    {
        Lang l("data/small_files/test1");
        REQUIRE(l[0] == 2);
        REQUIRE(l[757] == 1);
        REQUIRE(l[19682] == 1);
        REQUIRE(l[6094] == 1);
    }
}