#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lang.h"

TEST_CASE()
{
    Lang l("testing this shit doe");
    REQUIRE(l[0] == 0);
}