#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vectors.h"
#include <vector>

using std::vector;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Verify get_max_from_vector function")
{
	vector<int> set1{ 3,8,1,99,1000 };
	REQUIRE(get_max_from_vector(set1) == 1000);

	vector<int> set2{ 15,12,11,99,88 };
	REQUIRE(get_max_from_vector(set2) == 99);

	vector<int> set3{ 150,120,11,990,88888 };
	REQUIRE(get_max_from_vector(set3) == 88888);
}

TEST_CASE("Verify is_prime function")
{
	REQUIRE(is_prime(2) == true);
	REQUIRE(is_prime(4) == false);
	REQUIRE(is_prime(43) == true);
	REQUIRE(is_prime(44) == false);
}

TEST_CASE("Verify vector_of_primes function")
{
	vector<int> result1{ 2, 3, 5, 7 };
	REQUIRE(vector_of_primes(10) == result1);

	vector<int> result2{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	REQUIRE(vector_of_primes(50) == result2);
}
