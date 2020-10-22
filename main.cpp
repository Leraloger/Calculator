#include <main.h>


int main(int argc, char *argv[])
    {
        Calculator calc;
        calc.test_cases();
        //cout<<"stod(1,5): "<<stod("1.5")<<endl;
        calc.test_cases2();
        calc.loop();
        return 0;

    }

void Calculator::test_cases()
{
    string input = " +1.1 - 12 + 2 - 14";
    double res = sum_input_string(input);
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = "2 *4";
    res = sum_input_string(mul_input_string(input));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = " 2* 4 /2 +1";
    res = sum_input_string(mul_input_string(input));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = "2*(2+2+2)";
    res = sum_input_string(mul_input_string(find_brackets(input)));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = "2*(2+2)+(2+3)";
    res = sum_input_string(mul_input_string(find_brackets(input)));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = "2*((2+2)+(2+3))";
    res = sum_input_string(mul_input_string(find_brackets(input)));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = "-10 + (8*2.5) ";
    res = sum_input_string(mul_input_string(find_brackets(input)));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = "-(3/1,5)";
    input = regex_replace(input, regex{","}, ".");
    res = sum_input_string(mul_input_string(find_brackets(input)));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    input = "2*(2+2)+(-2*1+3)";
    res = sum_input_string(mul_input_string(find_brackets(input)));
    cout << "Input string: " << input<<endl;
    cout << "Result: "<<res<<endl;

    cout<<my_division("4","2")<<endl;
}

void Calculator::test_cases2()
{
    string input = "2 2";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 ()";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +k";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 @";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +$";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +!";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +?";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +;";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +:";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +k?";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +k&";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +#";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 _";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = ") 2";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "**6";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "++2";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "//5";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "+-1";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "-+ 4";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "*/ 2";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 /*";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 *-";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 *+";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 -*";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +*";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 /-";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 /+";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 +/";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "2 -/";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " * ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " / ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " + ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " - ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " -2 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " +2 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " * 2 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " *2 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " /2 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " (*) ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2*() ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " () ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2+(2 -3 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2+(2 +2) -3 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2/(2 +2) -3 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2*(2 +2) -3 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2 * (2 +2) -3 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2-(2 +2) -3 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = " 2-(2 +2/0) -3 ";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;

    input = "1/0";
    cout<<"Input: "<<input<<endl;
    cout<<find_bad_string(input)<<endl;
}

double Calculator::sum_input_string(string input)
{

    double result = 0;

    smatch sm;
    int pos = 0;
    regex r = regex{ "\\d+[\\.,]?\\d*" };
    string temp_string;

    if(regex_search(input, sm, r))
    {
        do
        {
            //cout << "lenght: "<<sm.length(0)<<" position: "<<sm.position(0)<<endl;
            pos += sm.position(0);
            //cout << "Position: "<<pos<<"\n";
            pos += sm.length(0);
            //cout << sm[0] << endl;
            temp_string = sm.prefix();
            //cout<< "temp_string: "<< temp_string<<endl;
            if(regex_search(temp_string,regex{"[-]+"}))
            {
                //cout<<"in minus\n";
                result = my_minus(result, sm[0]);
            }
            else
            {
                //cout<<"in plus\n";
                result = my_sum(result, sm[0]);
            }
            //cout << "Suffix: "<<sm.suffix()<<"\n";
            input = sm.suffix().str();
            //cout<< "end cycle_____\n";
        } while(regex_search(input, sm, r));
    }
    return result;
}

double my_sum(double a, string b)
{
    return a + stod(b);

}

double my_minus(double a, string b)
{
    return a - stod(b);
}

string Calculator::mul_input_string(string input)
{
    input = find_operation(input, "\\*", my_multiply);
    return find_operation(input, "/", my_division);


}

string Calculator::find_operation(string input, string operation, string (* operation_fun)(string a, string b))
{
    smatch sm;
    smatch sub_sm;
    regex num_r = regex{ "\\d+[\\.,]?\\d*" };
    string prefix_string, suffix_string, first, second, res;
    //cout<<"We find "<<operation<<endl;

    if(regex_search(input, sm, regex{operation}))
    {
        do
        {
            //cout << "lenght: "<<sm.length(0)<<" position: "<<sm.position(0)<<endl;
            //cout << "Position: "<<pos<<"\n";
            //cout << sm[0] << endl;
            prefix_string = sm.prefix();
            //cout<< "prefix_string: "<< prefix_string<<endl;

            while(regex_search(prefix_string, sub_sm,num_r))
            {
                //cout<< "prefix_string inside: "<< prefix_string<<endl;
                first = sub_sm[0];
                prefix_string = sub_sm.suffix();
                //cout<< "prefix_string inside: "<< prefix_string<<endl<<"----"<<endl;
            }
            //cout<< "First: "<< first<<endl;

            //cout << "Suffix: "<<sm.suffix()<<"\n";
            suffix_string = sm.suffix().str();
            regex_search(suffix_string, sub_sm,num_r);
            second = sub_sm[0];
            //cout<<"Second: "<< second<<endl;
            res = operation_fun(first, second);
            if (res == "err")
                return res;
            input = regex_replace(input, regex{first+" *"+operation+" *"+second},res);
            //cout<<"Input string: "<< input<<endl;

            //cout<< "end cycle_____\n";
        } while(regex_search(input, sm, regex{operation}));
    }

    return input;
}

string my_multiply(string a, string b)
{
    return to_string(stod(a) * stod(b));
}

string my_division(string a, string b)
{
    cout<<"a = "<<a<<", b= "<<b<<endl;
    return to_string(stod(a) / stod(b));
}

string Calculator::find_brackets(string input)
{
    //cout<<"ert\n";
    smatch sm;
    smatch sub_sm;
    string temp_input = input;
    //cout<<"hp\n";
    regex num_r = regex{ "\\d+[\\.,]?\\d*" };
    string prefix_string, suffix_string, first, second;
    //cout<<"ooops\n";
    if(regex_search(temp_input, sm, regex{"\\("}))
    {
        //cout<<"inside if\n";
        temp_input = sm.suffix();
        while(regex_search(temp_input, sm, regex{"\\("}))
        {
            //cout<<"in while\n";
            temp_input = sm.suffix();
        }
        regex_search(temp_input, sm, regex{"\\)"});
        temp_input = sm.prefix();
        double res = sum_input_string(mul_input_string(temp_input));
        //cout<<"res in brackets: "<<res<<endl;
        //cout<<"Temp input: "<<temp_input<<endl;
        //cout<<"Input before: "<<input<<endl;
        temp_input = regex_replace(temp_input, regex{"\\+"}, "\\+");
        temp_input = regex_replace(temp_input, regex{"\\*"}, "\\*");
        //cout<<temp_input<<endl;
        //cout<<regex_search(input, sm, regex{temp_input})<<endl;
        input = regex_replace(input, regex{"\\(" + temp_input + "\\)"},to_string(res));
        input = find_brackets(input);
        //cout<<"Input: "<<input<<endl;
    }

    //cout<<"before return\n";
    return input;
}

bool Calculator::find_bad_string(string input)
{
    bool res = false;
    res = res || regex_search(input, regex{"[a-zA-Z]+"});
    res = res || regex_search(input, regex{"[\\!@#$%^&_=\\?:;]+"});
    res = res || regex_search(input, regex{"\\d+ +\\d+"});
    res = res || regex_search(input, regex{"\\d+ *\\("});
    res = res || regex_search(input, regex{"\\) *\\d+"});

    res = res || regex_search(input, regex{"\\+ *\\+"});
    res = res || regex_search(input, regex{"- *-"});
    res = res || regex_search(input, regex{"\\* *-"});
    res = res || regex_search(input, regex{"\\* *\\+"});
    res = res || regex_search(input, regex{"/ *-"});
    res = res || regex_search(input, regex{"/ *\\+"});
    res = res || regex_search(input, regex{"- *\\+"});
    res = res || regex_search(input, regex{"\\+ *-"});
    res = res || regex_search(input, regex{"/ *\\*"});
    res = res || regex_search(input, regex{"\\*/"});
    res = res || regex_search(input, regex{"\\* *\\*"});
    res = res || regex_search(input, regex{"/ */"});
    res = res || regex_search(input, regex{"\\+ */"});
    res = res || regex_search(input, regex{"- */"});
    res = res || regex_search(input, regex{"- *\\*"});
    res = res || regex_search(input, regex{"\\+ *\\*"});

    res = res || regex_search(input, regex{"^ *\\*"});
    res = res || regex_search(input, regex{"^ *\\+ *$"});
    res = res || regex_search(input, regex{"^ *- *$"});
    res = res || regex_search(input, regex{"^ */"});
    res = res || regex_search(input, regex{"\\( *\\*"});
    res = res || regex_search(input, regex{"\\( */"});

    res = res || regex_search(input, regex{"\\( *\\)"});
    res = res || pair_brackets(input);
    res = res || regex_search(input, regex{"/ *0\\D"});
    res = res || regex_search(input, regex{"/ *0 *$"});
    return res;
}

bool Calculator::pair_brackets(string input)
{
    bool res = false;
    smatch sm;
    int count = 0;
    regex r1 = regex{ "\\(" };
    regex r2 = regex{ "\\)" };
    string temp_string = input;

    while(regex_search(temp_string, sm, r1))
    {
        temp_string = sm.suffix();
        count++;
    }

    temp_string = input;
    while(regex_search(temp_string, sm, r2))
    {
        temp_string = sm.suffix();
        count--;
    }

    if( count != 0)
    {
        res = true;
    }


    return res;
}

void Calculator::loop()
{
    string input = "";
    cout<<"Type numerical expression to get its result. If the string contains bad symbols\n"<<
            "the programm shows the error and  suggest you to type again. Type h for help\n";
    while(input != "q")
    {
        cout << "Enter string: ";
        getline(cin,input);
        if(input == "h")
        {
            cout<<"h -- help\nq -- exit\n";
            continue;
        }
        //cout<<"Bad string: "<<find_bad_string(input)<<endl;
        if(find_bad_string(input))
        {
            cout<<"Bad string\n";
        }
        else
        {
            input = regex_replace(input, regex{","}, ".");
            double res = sum_input_string(mul_input_string(find_brackets(input)));
            if((res - (int)res) != 0)
            {
                printf("%.2f\n",res);
            }
            else
            {
                printf("%i\n",(int)res);
            }
        }

    }
}

Calculator::Calculator()
{

}




