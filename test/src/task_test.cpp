#include "task_test.h"
#include <iostream>

void TaskTest::setUp() {
		this->objet_a_tester = new Task("",0,0);
}

void TaskTest::tearDown() {
		delete this->objet_a_tester;
}

void TaskTest::test_weightHigh() {
	this->objet_a_tester->name_= "weightHigh";
	Task* task = new Task("weightHigh", std::numeric_limits<unsigned int>::max(), 1);
	double expected = 0;
	double actual = task->ratioWV_;
	delete task;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(expected, actual, FLT_EPSILON);
}

void TaskTest::test_weightZero() {
	Task* task = new Task("weightZero", 0, 1);
	double expected = std::numeric_limits<double>::max();
	double actual = task->ratioWV_;
	delete task;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(expected, actual, FLT_EPSILON);
}

void TaskTest::test_valueZero() {
	Task* task = new Task("valueZero", 1, 0);
	double expected = 0;
	double actual = task->ratioWV_;
	delete task;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(expected, actual, FLT_EPSILON);
}
