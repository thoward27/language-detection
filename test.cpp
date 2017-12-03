#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lang.h"

TEST_CASE()
{
    SECTION("Three spaces")
    {
        Lang l("   ");
        REQUIRE(l[0] == 1);
    }
    SECTION("Four Spaces")
    {
        Lang l("    ");
        REQUIRE(l[0] == 2);
    }
    SECTION("Three a's")
    {
        Lang l("aaa");
        REQUIRE(l[757] == 1);
    }
    SECTION("Three z's")
    {
        Lang l("zzz");
        REQUIRE(l[19682] == 1);
    }
    SECTION("his")
    {
        Lang l("    aaa his zzz");
        REQUIRE(l[0] == 2);
        REQUIRE(l[757] == 1);
        REQUIRE(l[19682] == 1);
        REQUIRE(l[6094] == 1);
    }
}