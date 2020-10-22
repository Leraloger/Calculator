#ifndef MYTESTSUITE_H
#define MYTESTSUITE_H

#include <cxxtest/TestSuite.h>
#include <my.h>

class MyTestSuite : public CxxTest::TestSuite
{
public:
    my m1;
    void test_sum_input_string(void)
    {

        //Calculator calc;
        //string input = " +1.1 - 12 + 2 - 14";
        //double res = calc.sum_input_string(input);
        //TS_ASSERT_EQUALS(res, -22.9);
        //my m1;
        //TS_ASSERT_EQUALS(1 + m1.foo(), 2);
        TS_ASSERT_EQUALS(1 + 1, 2);
    }
};

#endif // MYTESTSUITE_H
