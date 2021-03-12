// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <random>
#include "Sorted_List.h"
#include <string>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};

  REQUIRE( l.is_empty() == true );
  REQUIRE( l.size() == 0 );
}


TEST_CASE( "check create node and is empty! AND SIZE!!" ) {
  Sorted_List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
  CHECK_FALSE(obj.is_empty());
  CHECK(obj.size()==4);
}

TEST_CASE( "Inserting At End and to string" ) {
  Sorted_List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
  obj.insert_end(37);
  CHECK_FALSE(obj.is_empty());
  CHECK(obj.to_string() == "25 50 90 40 37 ");
}

TEST_CASE( "Inserting At beging and to string" ) {
  Sorted_List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
  obj.insert_start(37);
  CHECK_FALSE(obj.is_empty());
  CHECK(obj.to_string() == "37 25 50 90 40 ");
}

TEST_CASE( "Sorted string" ) {
  Sorted_List obj;
	obj.insert(25);
	obj.insert(50);
	obj.insert(90);
	obj.insert(40);
  obj.insert(37);
  CHECK_FALSE(obj.is_empty());
  CHECK(obj.to_string() == "25 37 40 50 90 ");
}
