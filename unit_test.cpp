//test
#include "base.hpp"
#include "container.hpp"
#include "sort.hpp"
// #include "decorator.hpp"
// #include "stringifyDec.hpp"
// #include "evaluateDec.hpp"
#include "visitor.hpp"
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

// TEST(CountVisitorTest, OneOpTest) {
// 	Base* op2 = new Sub(new Op(10), new Op(20));
// 	Base * op4 = new Add(op2, new Op(30));
// 	Base* dummy4 = new Add(op4,op2);
// 	CountVisitor * cv3 = new CountVisitor();
// 	PreorderIterator *pi3 = new PreorderIterator(dummy4);
// 	pi3->first();
// 	while(pi3->is_done() == false){
// 	    pi3->current()->accept(cv3);
// 	    pi3->next();
// 	}
// 	// EXPECT_EQ(cv->sub_count(), 1);
// 	// EXPECT_EQ(cv->abs_count(), 1);
// 	// EXPECT_EQ(cv->floor_count(), 1);
// 	// EXPECT_EQ(cv->div_count(), 1);
// 	// EXPECT_EQ(cv->paren_count(), 1);
// 	EXPECT_EQ(cv3->op_count(), 3);
// }


TEST(CountVisitorTest, MainTestOnlyOneWeNeedIThink) {
	Base* op2 = new Sub( new Trunc(new Abs(new Op(-4))), new Floor(new Op(1.432)));
	Base* op4 = new Pow(new Div( new Paren(new Op(6)), (new Add(new Op(3), new Ceil(new Op(1))))), new Op(2));

	Base* dummy = new Add(op4,op2);
	CountVisitor *cv = new CountVisitor();
	PreorderIterator *pi = new PreorderIterator(dummy);
	pi->first();
	while(pi->is_done() == false){
	    pi->current()->accept(cv);
	    pi->next();
	}

	EXPECT_EQ(cv->div_count(), 1);
	EXPECT_EQ(cv->sub_count(), 1);
	EXPECT_EQ(cv->abs_count(), 1);
	EXPECT_EQ(cv->floor_count(), 1);
	EXPECT_EQ(cv->paren_count(), 1);
	EXPECT_EQ(cv->trunc_count(), 1);
	EXPECT_EQ(cv->add_count(), 1);
	EXPECT_EQ(cv->ceil_count(), 1);
	EXPECT_EQ(cv->op_count(), 6);
	EXPECT_EQ(cv->pow_count(), 1);
}

// TEST(CountVisitorTest2, MainTestOnlyOneWeNeedIThink) {
// 	Base* op2 = new Sub( new Abs(new Op(-4)), new Floor(new Op(1.432)));
// 	Base* op4 = new Div( new Paren(new Op(6)), new Op(3));
//
// 	Base* dummy = new Add(op4,op2);
// 	CountVisitor *cv = new CountVisitor();
// 	PreorderIterator *pi = new PreorderIterator(dummy);
// 	pi->first();
// 	while(pi->is_done() == false){
// 	    pi->current()->accept(cv);
// 	    pi->next();
// 	}
// 	EXPECT_EQ(cv->sub_count(), 1);
// 	EXPECT_EQ(cv->abs_count(), 1);
// 	EXPECT_EQ(cv->floor_count(), 1);
// 	EXPECT_EQ(cv->div_count(), 1);
// 	EXPECT_EQ(cv->paren_count(), 1);
// 	EXPECT_EQ(cv->op_count(), 4);
// }


int main(int argc, char **argv) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
