#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"



TEST_CASE("is valid?")
{
  Time const t1{13, 29, 32};
  Time const t2{42, 69, 420};
  Time const t3{00,00,00};
  Time const t4{23,59,59};
  REQUIRE(is_valid(t1));
  REQUIRE_FALSE(is_valid(t2));
  CHECK(is_valid(t3));
  CHECK(is_valid(t4));
}

TEST_CASE("To string")
{
  Time const t1{13, 29, 32};
  Time const t3{00,00,00};
  Time const t4{23,59,59};
  CHECK(to_string(t1,24)== "13:29:32");
  CHECK(to_string(t3,12)=="00:00:00 [am]");
  CHECK(to_string(t4,12)=="11:59:59 [pm]");
}


TEST_CASE("+")
{
  std::string test1;
  std::string test2;
  Time  t1{15,13,23};
  Time  t2{23,59,59};
  test2 = to_string(t2+1,24);
  test1 = to_string(t1+1,24);
  CHECK(test1=="15:13:24");
  CHECK(test2=="00:00:00");
}


TEST_CASE("-")
{
  std::string test1;
  std::string test2;
  Time  t1{15,13,23};
  Time  t2{00,00,00};
  test2 = to_string(t2-1,24);
  test1 = to_string(t1-1,24);
  CHECK(test1=="15:13:22");
  CHECK(test2=="23:59:59");
}

TEST_CASE("++i")
{
  std::string test1;
  std::string test2;
  Time  t1{12,23,23};
  Time  t2{15,59,59};
  test1 = to_string(t1++,24);
  test2 = to_string(t2++,24);
  CHECK(test1=="12:23:24");
  CHECK(test2=="16:00:00");
}


TEST_CASE("i++")
{
  std::string test1;
  std::string test2;
  Time  t1{12,23,23};
  Time  t2{15,59,59};
  test1 = to_string(++t1,24);
  test2 = to_string(++t2,24);
  CHECK(test1=="12:23:24");
  CHECK(test2=="16:00:00");
}

TEST_CASE("--i")
{
  std::string test1;
  std::string test2;
  Time  t1{12,23,23};
  Time  t2{00,00,00};
  test1 = to_string(t1--,24);
  test2 = to_string(t2--,24);
  CHECK(test1=="12:23:22");
  CHECK(test2=="23:59:59");
}
TEST_CASE("i--")
{
  std::string test1;
  std::string test2;
  Time  t1{12,23,23};
  Time  t2{00,00,00};
  test1 = to_string(--t1,24);
  test2 = to_string(--t2,24);
  CHECK(test1=="12:23:22");
  CHECK(test2=="23:59:59");
}

TEST_CASE(">")
{
  Time  t1{12,23,23};
  Time  t2{00,00,00};
  CHECK(t1>t2);
}

TEST_CASE("<")
{
  Time  t1{22,23,23};
  Time  t2{10,00,00};
  CHECK_FALSE(t1<t2);
}

TEST_CASE("==")
{
  Time  t1{22,23,23};
  Time  t2{10,00,00};
  CHECK_FALSE(t1==t2);
  CHECK(t1==t1);
}

TEST_CASE("<=")
{
  Time  t1{22,23,23};
  Time  t2{10,00,00};
  CHECK_FALSE(t1<=t2);
  CHECK(t2<=t1);
}

TEST_CASE(">=")
{
  Time  t1{22,23,23};
  Time  t2{10,00,00};
  CHECK_FALSE(t2>=t1);
  CHECK(t1>=t2);
  CHECK(t1>=t1);
}

TEST_CASE("!=")
{
  Time  t1{22,23,23};
  Time  t2{10,00,00};
  CHECK_FALSE(t2!=t2);
  CHECK(t1!=t2);
  CHECK(t2!=t1);
}

TEST_CASE("<<")
{
  Time  t1{22,23,23};
  std::ostringstream os{};
  os << t1;
  CHECK(os.str()== "22:23:23");
}

TEST_CASE(">>")
{
  Time t{};
  std::stringstream ss{"14:47:34"};
  ss >> t;
  REQUIRE(t.hours==14);
  REQUIRE(t.minutes==47);
  REQUIRE(t.seconds==34);
  std::stringstream ss1{"25:47:34"};
  ss1 >> t; //t should not change because time is not valid
  REQUIRE(t.hours==14);
  REQUIRE(t.minutes==47);
  REQUIRE(t.seconds==34);
}