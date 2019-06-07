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

TEST(CountVisitorTest, MainTestOnlyOneWeNeedIThink) {
  Base* op1 = new Add( new Rand(), new Trunc(new Op(1.432)));
	Base* op2 = new Sub( new Abs(new Op(-4)), new Floor(new Op(1.432)));
	Base* op3 = new Mult( new Ceil(new Op(5.5)), new Pow(new Op(2), new Op(2)));
	Base* op4 = new Div( new Paren(new Op(6)), new Op(3));

	Base* dummy = new Add(op4,op2);
	CountVisitor *cv = new CountVisitor();
	PreorderIterator *pi = new PreorderIterator(dummy);
	pi->first();
	while(pi->is_done() == false){
	    pi->current()->accept(cv);
	    pi->next();
	}

	EXPECT_EQ(cv->add_count(), 1);
	EXPECT_EQ(cv->op_count(),6);
	EXPECT_EQ(cv->trunc_count(),1);
	EXPECT_EQ(cv->abs_count(),1);
	EXPECT_EQ(cv->div_count(),1);
	EXPECT_EQ(cv->sub_count(),1);
	EXPECT_EQ(cv->pow_count(),1);
	EXPECT_EQ(cv->ceil_count(),1);
	EXPECT_EQ(cv->floor_count(),1);
	EXPECT_EQ(cv->rand_count(),1);
	EXPECT_EQ(cv->paren_count(),1);
}


int main(int argc, char **argv) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
