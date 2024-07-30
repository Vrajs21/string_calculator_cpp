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
    string  delimiter = ",";
    vector<int> negatives;
    int sum = 0;

    if (numbers.substr(0, 2) == "//")
    {
        size_t pos = numbers.find("\n");
        if (numbers[2] == '[' && numbers.find(']', 2) != std::string::npos) {
            delimiter = numbers.substr(3, numbers.find(']', 2) - 3);
        } else {
            delimiter = numbers[2];
        }
        input = numbers.substr(pos + 1);
    }


    string delimiters_regex = regex_replace(delimiter, regex(R"([.^$|()\\[\]{}*+?])"), R"(\$&)");
    delimiters_regex = "(" + delimiters_regex + "|\n)";
    regex re(delimiters_regex);

    sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
    vector<std::string> tokens{first, last};
    

    for (const auto& token : tokens)
    {
            if (!token.empty())
            {
                try
                {
                    int num = stoi(token);
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
                    throw invalid_argument("Invalid input: " + token);
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