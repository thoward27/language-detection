#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lang.h"

TEST_CASE()
{
    SECTION("Three Character Tests")
    {
        REQUIRE(Lang("   ")[0] == 1);
        REQUIRE(Lang("aaa")[757] == 1);
        REQUIRE(Lang("zzz")[19682] == 1);
    }
    SECTION(">3 Character Tests")
    {
        REQUIRE(Lang("    ")[0] == 2);
        REQUIRE(Lang("     ")[0] == 3);
    }
    SECTION("Sentence tests")
    {
        Lang l("    aaa his zzz");
        REQUIRE(l[0] == 2);
        REQUIRE(l[757] == 1);
        REQUIRE(l[19682] == 1);
        REQUIRE(l[6094] == 1);
    }
    SECTION("Invalid Init")
    {
        REQUIRE_THROWS(Lang("aa12@;;"));

    }
}