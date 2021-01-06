#ifndef TASK_TEST_H
#define TASK_TEST_H

#include "../../src/Task.h"

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TaskTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TaskTest);
    CPPUNIT_TEST(test_weightHigh);
    CPPUNIT_TEST(test_weightZero);
    CPPUNIT_TEST(test_valueZero);
    CPPUNIT_TEST_SUITE_END();
    
private:
	Task* objet_a_tester;
    
public:
	// SetUp & TearDown
    void setUp();
    void tearDown();
    
    // Tests functions
    void test_weightHigh();
    void test_weightZero();
    void test_valueZero();
};

#endif //TASK_TEST_H