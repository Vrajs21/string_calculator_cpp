#include "../include/string_calculator.hpp"
#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
using namespace std;

int StringCalculator::add(const string &numbers)
{
    if (numbers.empty())
    {
        return 0;
    }
    if (numbers.length() == 1 && isdigit(numbers[0]))
    {
        return (numbers[0] - '0');
    }

    string input = numbers;
    char delimiter = ',';
    vector<int> negatives;
    int sum = 0;

    if (numbers.substr(0, 2) == "//")
    {
        size_t pos = numbers.find("\n");
        delimiter = numbers[2];
        input = numbers.substr(pos + 1);
    }

    stringstream ss(input);
    string token;

    while (getline(ss, token, '\n'))
    {
        stringstream line_ss(token);
        string num_str;

        while (getline(line_ss, num_str, delimiter))
        {
            if (!num_str.empty())
            {
                try
                {
                    int num = stoi(num_str);
                    if (num < 0)
                    {
                        negatives.push_back(num);
                    }
                    else if (num <= 1000)
                    {
                        sum += num;
                    }
                }
                catch (const invalid_argument &)
                {
                    throw invalid_argument("Invalid input: " + num_str);
                }
            }
        }
    }

    if (!negatives.empty())
    {
        string msg = "negative numbers not allowed ";
        for (size_t i = 0; i < negatives.size(); ++i)
        {
            msg += to_string(negatives[i]);
            if (i < negatives.size() - 1)
            {
                msg += ",";
            }
        }
        throw invalid_argument(msg);
    }

    return sum;
}