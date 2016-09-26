/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test {
 protected:
  FieldTest() {}
  virtual ~FieldTest() {}
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST(FieldTest, placeMineInBounds) {
  Field minefield;

  minefield.placeMine(4, 5);
  ASSERT_EQ(MINE_HIDDEN, minefield.get(4, 5));
}

TEST(Field, placeMineOutOfBoundsUnder) {
  Field minefield;
  minefield.placeMine(-1, 0);
  ASSERT_ANY_THROW(minefield.get(-1, 0));
}

TEST(Field, revealAdjacentOutOfBoundsUnder) {
  Field minefield;
  ASSERT_ANY_THROW(minefield.revealAdjacent(-1, 1));
}

TEST(FieldTest, placeMineOutOfBoundsOver) {
  Field minefield;
  ASSERT_ANY_THROW(minefield.placeMine(10, 10));
}
