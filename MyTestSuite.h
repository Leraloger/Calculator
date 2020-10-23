#ifndef MYTESTSUITE_H
#define MYTESTSUITE_H

#include <cxxtest/TestSuite.h>
#include <calculator.h>
#include <string>


using namespace std;

class CalculatorTestSuite : public CxxTest::TestSuite
{
public:
    Calculator calc;
    string input;
    void test_sum_input_string(void)
    {


        input = " +1.1 - 12 + 2 - 14";
        double res = calc.sum_input_string(input);
        TS_ASSERT_EQUALS(res, -22.9);
    }

    void test_sum_and_mul()
    {
        input = " 2* 4 /2 +1";
        double res = calc.sum_input_string(calc.mul_input_string(input));
        TS_ASSERT_DELTA(res, 5, 0.01);

        input = "2*(2+2+2)";
        res = calc.sum_input_string(calc.mul_input_string(calc.find_brackets(input)));
        TS_ASSERT_DELTA(res, 12, 0.01);

        input = "2*(2+2)+(2+3)";
        res = calc.sum_input_string(calc.mul_input_string(calc.find_brackets(input)));
        TS_ASSERT_DELTA(res, 13, 0.01);

        input = "2*((2+2)+(2+3))";
        res = calc.sum_input_string(calc.mul_input_string(calc.find_brackets(input)));
        TS_ASSERT_DELTA(res, 18, 0.01);

        input = "-10 + (8*2.5) ";
        res = calc.sum_input_string(calc.mul_input_string(calc.find_brackets(input)));
        TS_ASSERT_DELTA(res, 10, 0.01);

        input = "-(3/1,5)";
        input = regex_replace(input, regex{","}, ".");
        res = calc.sum_input_string(calc.mul_input_string(calc.find_brackets(input)));
        TS_ASSERT_DELTA(res, -2, 0.01);

        input = "2*(2+2)+(-2*1+3)";
        res = calc.sum_input_string(calc.mul_input_string(calc.find_brackets(input)));
        TS_ASSERT_DELTA(res, 9, 0.01);

    }

    void test_mul_input_string(void)
    {
        input = "2 *4";
        double res = calc.sum_input_string(calc.mul_input_string(input));
        TS_ASSERT_DELTA(res, 8, 0.01);
    }

    void test_find_operation()
    {
        input = "2 *4";
        string res = calc.find_operation(input,"\\*", my_multiply);
        TS_ASSERT_EQUALS(stod(res), 8);

        input = "4 /2";
        res = calc.find_operation(input,"/", my_division);
        TS_ASSERT_EQUALS(stod(res), 2);
    }

    void test_find_brackets()
    {
        input = "4 *(1.5 + 2.5)";
        string res = calc.find_brackets(input);
        TS_ASSERT_EQUALS(res, "4 *4.000000");

        input = "4 *((1 + 0.5) + 2.5)";
        res = calc.find_brackets(input);
        TS_ASSERT_EQUALS(res, "4 *4.000000");
    }

    void test_find_bad_string()
    {
        string input = "2 2";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 ()";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +k";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 @";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +$";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +!";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +?";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +;";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +:";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +k?";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +k&";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +#";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 _";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = ") 2";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "**6";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "++2";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "//5";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "+-1";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "-+ 4";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "*/ 2";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 /*";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 *-";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 *+";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 -*";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +*";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 /-";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 /+";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 +/";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "2 -/";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " * ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " / ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " + ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " - ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " -2 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),false);

        input = " +2 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),false);

        input = " * 2 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " *2 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " /2 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " (*) ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " 2*() ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " () ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " 2+(2 -3 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = " 2+(2 +2) -3 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),false);

        input = " 2/(2 +2) -3 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),false);

        input = " 2*(2 +2) -3 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),false);

        input = " 2 * (2 +2) -3 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),false);

        input = " 2-(2 +2) -3 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),false);

        input = " 2-(2 +2/0) -3 ";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);

        input = "1/0";
        TS_ASSERT_EQUALS( calc.find_bad_string(input),true);
    }

    void test_pair_brackets()
    {
        input = "(2 *4)";
        bool res = calc.pair_brackets(input);
        TS_ASSERT_EQUALS(res, false);

        input = "2 *4)";
        res = calc.pair_brackets(input);
        TS_ASSERT_EQUALS(res, true);

        input = "(2 *4";
        res = calc.pair_brackets(input);
        TS_ASSERT_EQUALS(res, true);
    }


    void test_my_sum(void)
    {
        TS_ASSERT_DELTA(my_sum(1.0,"1.2"),2.2,0.01);
        TS_ASSERT_DELTA(my_sum(0.0,"5.2"),5.2,0.01);
    }

    void test_my_minus()
    {
        double res = my_minus(1.0,"1.2");
        TS_ASSERT_DELTA(res, -0.2, 0.01);
        TS_ASSERT_DELTA(my_minus(0.0,"5.2"),-5.2, 0.01);
    }

    void test_my_multiplication()
    {
        string res = "1.2";
        TS_ASSERT_DELTA(stod(my_multiply("1","1.2")),stod(res),0.01);
        TS_ASSERT_DELTA(stod(my_multiply("4","5")),stod("20"),0.01);
    }

    void test_my_division()
    {
        TS_ASSERT_DELTA(stod(my_division("1","1.2")),stod("0.833333"),0.01);
        TS_ASSERT_DELTA(stod(my_division("5","2")),stod("2.5"),0.01);
    }

};

#endif // MYTESTSUITE_H
