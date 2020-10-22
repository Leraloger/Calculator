#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;


string my_multiply(string a, string b);
string my_division(string a, string b);

double my_sum(double a, string b);
double my_minus(double a, string b);



class Calculator
{
public:
    Calculator();
    double sum_input_string(string input);

    string mul_input_string(string input);



    string find_operation(string input, string operation, string (* operation_fun)(string a, string b));



    string find_brackets(string input);

    bool find_bad_string(string input);

    bool pair_brackets(string input);

    void test_cases();
    void test_cases2();
    void loop();

};

#endif // MAIN_H
