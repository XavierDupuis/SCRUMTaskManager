#include <cppunit/ui/text/TestRunner.h>
#include "task_test.h"

int main( int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(TaskTest::suite());
    runner.run();
    return 0;
}
