#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"
#include "rectangle.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify calculate area")
{
	Rect rectangles(4, 5);
	REQUIRE(rectangles.get_area() == 20);
}
/*
Write a test case to test that a rectangle of height 4 and width 5 returns an area of 20.  You'll have to use the rectangle class method get_area to use in your test case*/