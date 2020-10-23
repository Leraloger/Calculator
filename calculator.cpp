#include "calculator.h"

double Calculator::sum_input_string(string input)
/*
 * Суммирование чисел в строке. В строке есть только + и -.
 */
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
            pos += sm.position(0);
            pos += sm.length(0);
            temp_string = sm.prefix();
            if(regex_search(temp_string,regex{"[-]+"}))
            {
                result = my_minus(result, sm[0]);
            }
            else
            {
                result = my_sum(result, sm[0]);
            }
            input = sm.suffix().str();
        } while(regex_search(input, sm, r));
    }
    return result;
}

double my_sum(double a, string b)
/*
 * Функция для суммирования двух чисел.
*/
{
    return a + stod(b);

}

double my_minus(double a, string b)
/*
 * Функция для вычитания двух чисел
 */
{
    double res = a - stod(b);
    return res;
}

string Calculator::mul_input_string(string input)
/*
 * Функция для нахождения всех перемножений и делений в строке.
 * Заменяет произведение или деление двух чисел на их результат.
 * Не трогает + и -.
 */
{
    input = find_operation(input, "\\*", my_multiply);
    return find_operation(input, "/", my_division);


}

string Calculator::find_operation(string input, string operation, string (* operation_fun)(string a, string b))
/*
 * Функция для нахождения конкретной операции в строке, вычислении результата с помощью переданой функции и
 * запись результата обратно в строку.
 */
{
    smatch sm;
    smatch sub_sm;
    regex num_r = regex{ "\\d+[\\.,]?\\d*" };
    string prefix_string, suffix_string, first, second, res;

    if(regex_search(input, sm, regex{operation}))
    {
        do
        {
            prefix_string = sm.prefix();
            while(regex_search(prefix_string, sub_sm,num_r))
            {
                first = sub_sm[0];
                prefix_string = sub_sm.suffix();
            }
            suffix_string = sm.suffix().str();
            regex_search(suffix_string, sub_sm,num_r);
            second = sub_sm[0];
            res = operation_fun(first, second);
            if (res == "err")
                return res;
            input = regex_replace(input, regex{first+" *"+operation+" *"+second},res);
        } while(regex_search(input, sm, regex{operation}));
    }

    return input;
}

string my_multiply(string a, string b)
/*
 * Функция для перемножения двух чисел в виде строк.
 */
{
    return to_string(stod(a) * stod(b));
}

string my_division(string a, string b)
/*
 * Функция для деления двух чисел в виде строк.
 * Не обработывает деление на нуль. Для этого есть find_bad_string
 */
{
    return to_string(stod(a) / stod(b));
}

string Calculator::find_brackets(string input)
/*
 * Функция для нахождения всех скобок в строке и вычислении выражения в скобках.
 * Результат записывается обратно в строку на местро скобок и выражения между ними.
 * Работает рекурсивно.
 */
{
    smatch sm;
    smatch sub_sm;
    string temp_input = input;
    regex num_r = regex{ "\\d+[\\.,]?\\d*" };
    string prefix_string, suffix_string, first, second;
    if(regex_search(temp_input, sm, regex{"\\("}))
    {
        temp_input = sm.suffix();
        while(regex_search(temp_input, sm, regex{"\\("}))
        {
            temp_input = sm.suffix();
        }
        regex_search(temp_input, sm, regex{"\\)"});
        temp_input = sm.prefix();
        double res = sum_input_string(mul_input_string(temp_input));
        temp_input = regex_replace(temp_input, regex{"\\+"}, "\\+");
        temp_input = regex_replace(temp_input, regex{"\\*"}, "\\*");
        input = regex_replace(input, regex{"\\(" + temp_input + "\\)"},to_string(res));
        input = find_brackets(input);
    }
    return input;
}

bool Calculator::find_bad_string(string input)
/*
 * Функция для нахождения всех недопустимых строк.
 * Если строка не удовлетсворяет требования возвращает true,
 * иначе false.
 */
{
    bool res = false;
    res = res || regex_search(input, regex{"[a-zA-Zа-яА-Я]+"});
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
/*
 * Функция проверяет парность всех скобок. Если
 * количество скобок четно, то возвращает false,
 *  иначе true. Используется в find_bad_string
 */
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
/*
 * Функция для взаимодействия с пользователем.
 */
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
/*
 * Конструктор.
 */
{

}
