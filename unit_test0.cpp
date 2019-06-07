//test
#include "base.hpp"
#include "container.hpp"
#include "sort.hpp"
// #include "decorator.hpp"
// #include "stringifyDec.hpp"
// #include "evaluateDec.hpp"
#include "gtest/gtest.h"
#include "menu.hpp"
#include "Iterator.hpp"
//#include "base_factory.hpp"
#include "menu.hpp"
#include "command.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

TEST(IteratorTest, NullIteratorOp)  {
	Base* blah = new Op(10);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), nullptr);
	EXPECT_EQ(blah->get_right(), nullptr);
	homie->first();
	EXPECT_EQ(homie->current(), nullptr);
	homie->next();
	EXPECT_EQ(homie->current(), nullptr);
	EXPECT_TRUE(homie->is_done());
}

TEST(IteratorTest, UnaryIteratorAbs) {
	Base* brother = new Op(-10);
	Base* blah = new Abs(brother);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), brother);
	EXPECT_EQ(blah->get_right(), nullptr);
	homie->first();
	EXPECT_EQ(homie->current(), brother);
	homie->next();
	EXPECT_EQ(homie->current(), nullptr);
	EXPECT_TRUE(homie->is_done());
}

TEST(IteratorTest, UnaryIteratorTrunc) {
	Base* brother = new Op(300);
	Base* blah = new Abs(brother);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), brother);
	EXPECT_EQ(blah->get_right(), nullptr);
	homie->first();
	EXPECT_EQ(homie->current(), brother);
	homie->next();
	EXPECT_EQ(homie->current(), nullptr);
	EXPECT_TRUE(homie->is_done());
}

TEST(IteratorTest, UnaryIteratorParen) {
	Base* brother = new Op(100);
	Base* blah = new Abs(brother);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), brother);
	EXPECT_EQ(blah->get_right(), nullptr);
	homie->first();
	EXPECT_EQ(homie->current(), brother);
	homie->next();
	EXPECT_EQ(homie->current(), nullptr);
	EXPECT_TRUE(homie->is_done());
}

TEST(IteratorTest, UnaryIteratorSeal) {
	Base* brother = new Op(8);
	Base* blah = new Abs(brother);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), brother);
	EXPECT_EQ(blah->get_right(), nullptr);
	homie->first();
	EXPECT_EQ(homie->current(), brother);
	homie->next();
	EXPECT_EQ(homie->current(), nullptr);
	EXPECT_TRUE(homie->is_done());
}

TEST(IteratorTest, BinaryIteratorAdd) {
	Base* op1 = new Op(10);
	Base* op2 = new Op(20);
	Base* blah = new Add(op1, op2);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), op1); //left val 10
	EXPECT_EQ(blah->get_right(), op2); //right val 20
	homie->first();
	EXPECT_EQ(homie->current(), op1); //10
	homie->next();
	EXPECT_EQ(homie->current(), op2); //20
	// homie->next();
	EXPECT_TRUE(homie->is_done());
}


TEST(IteratorTest, BinaryIteratorSub) {
	Base* op1 = new Op(10);
	Base* op2 = new Op(20);
	Base* blah = new Sub(op1, op2);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), op1); //left val 10
	EXPECT_EQ(blah->get_right(), op2); //right val 20
	homie->first();
	EXPECT_EQ(homie->current(), op1); //10
	homie->next();
	EXPECT_EQ(homie->current(), op2); //20
	// homie->next();
	EXPECT_TRUE(homie->is_done());
}

TEST(IteratorTest, BinaryIteratorMult) {
	Base* op1 = new Op(10);
	Base* op2 = new Op(20);
	Base* blah = new Mult(op1, op2);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), op1); //left val 10
	EXPECT_EQ(blah->get_right(), op2); //right val 20
	homie->first();
	EXPECT_EQ(homie->current(), op1); //10
	homie->next();
	EXPECT_EQ(homie->current(), op2); //20
	// homie->next();
	EXPECT_TRUE(homie->is_done());
}


TEST(IteratorTest, BinaryIteratorPow) {
	Base* op1 = new Op(2);
	Base* op2 = new Op(5);
	Base* blah = new Pow(op1, op2);
	Iterator* homie = blah->create_iterator();
	EXPECT_EQ(blah->get_left(), op1);
	EXPECT_EQ(blah->get_right(), op2);
	homie->first();
	EXPECT_EQ(homie->current(), op1);
	homie->next();
	EXPECT_EQ(homie->current(), op2);
	// homie->next();
	EXPECT_TRUE(homie->is_done());
}

int main(int argc, char **argv) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
