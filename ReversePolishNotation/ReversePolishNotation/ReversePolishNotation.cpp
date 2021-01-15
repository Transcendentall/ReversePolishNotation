#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

int ReversePolishNotationFunction(char* input) {
    stack <char> steck;
    stack <char> steck2;




    int otvet;
    const int N = 200;
    char output[N];
    otvet = 0;
    int j = 0;
    for (j = 0; j < N; ++j)
    {
        output[j] = 0;
    }
    int i = 0;
    int istack = 0;
    int ioutput = 0;
    while (input[i] != 0)
    {
        if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/') || (input[i] == '(') || (input[i] == ')'))
        {
            if ((istack > 0))
            {

                if (((input[i] == '+') || (input[i] == '-')) && (((steck.top() == '+') || (steck.top() == '-') || (steck.top() == '*') || (steck.top() == '/'))))
                {


                    output[ioutput] = steck.top();
                    ++ioutput;
                    steck.pop();
                    --istack;


                    steck.push(input[i]);
                    ++istack;
                }
                else
                {

                    if (((input[i] == '*') || (input[i] == '/')) && (((steck.top() == '*') || (steck.top() == '/'))))
                    {

                        output[ioutput] = steck.top();
                        ++ioutput;
                        steck.pop();
                        --istack;


                        steck.push(input[i]);
                        ++istack;

                    }
                    else
                    {
                        if (((input[i] == ')')))
                        {

                            while (steck.top() != '(')
                            {
                                if (((steck.top() == '+') || (steck.top() == '-') || (steck.top() == '*') || (steck.top() == '/')))
                                {

                                    output[ioutput] = steck.top();
                                    ++ioutput;
                                    steck.pop();
                                    --istack;
                                }

                            }

                            steck.pop();
                            --istack;
                        }
                        else
                        {

                            steck.push(input[i]);
                            ++istack;


                        }
                    }
                }
            }
            else
            {

                steck.push(input[i]);
                ++istack;


            }
        }
        else
        {
            if ((input[i] == '0') || (input[i] == '1') || (input[i] == '2') || (input[i] == '3') || (input[i] == '4') || (input[i] == '5') || (input[i] == '6') || (input[i] == '7') || (input[i] == '8') || (input[i] == '9'))
            {
                output[ioutput] = input[i];
                ++ioutput;
            }
        }
        ++i;
    }
    while (istack > 0)
    {
        output[ioutput] = steck.top();
        ++ioutput;
        steck.pop();
        --istack;
    }
 
//    cout << endl << "Reverse polish notation: " << endl << output << endl << endl; //вывод выражения в обратной польской записи; если нужно, то его надо раскомментировать

    istack = 0;
    ioutput = 0;
    int a;
    int b;
    int c;
    while (output[ioutput] != 0)
    {
        if ((output[ioutput] == '0') || (output[ioutput] == '1') || (output[ioutput] == '2') || (output[ioutput] == '3') || (output[ioutput] == '4') || (output[ioutput] == '5') || (output[ioutput] == '6') || (output[ioutput] == '7') || (output[ioutput] == '8') || (output[ioutput] == '9'))
        {
            steck2.push(output[ioutput] - 48);
            ++istack;
        }
        else
        {
            if (istack > 1)
            {
                if ((output[ioutput] == '+') || (output[ioutput] == '-') || (output[ioutput] == '*') || (output[ioutput] == '/'))
                {
                    a = steck2.top();
                    steck2.pop();
                    --istack;
                    b = steck2.top();
                    steck2.pop();
                    --istack;
                    if (output[ioutput] == '+')
                    {
                        c = b + a;
                        steck2.push(c);
                        ++istack;
                    }
                    else
                        if (output[ioutput] == '-')
                        {
                            c = b - a;
                            steck2.push(c);
                            ++istack;

                        }
                        else
                            if (output[ioutput] == '*')
                            {
                                c = b * a;
                                steck2.push(c);
                                ++istack;

                            }
                            else
                                if (output[ioutput] == '/')
                                {
                                    if (a != 0)
                                    {
                                        c = b / a;
                                        steck2.push(c);
                                        ++istack;
                                    }
                                    else
                                    {
                                        cout << "ACHTUNG!!! Delenie na 0 zapresheno! Dannaya komanda budet zamenena na delenie na 1.";
                                        c = b;
                                        steck2.push(c);
                                        ++istack;
                                    }


                                }
                }
            }
        }
        ++ioutput;
    }

    return (int)steck2.top();

}