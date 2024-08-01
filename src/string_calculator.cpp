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

    CheckNagtive(numbers);
    vector<string> Extracted_numbers = getTokens(numbers);
    int sum = 0;
    for (const auto &token : Extracted_numbers)
    {
        if (!token.empty())
        {
            try
            {
                int num = stoi(token);

                if (num <= 1000)
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

    return sum;
}

void StringCalculator::CheckNagtive(const string &numbers)
{
    vector<int> negatives_numbers;
    int num = 0;
    bool negative = false;

    for (char c : numbers)
    {
        if (c == '-')
        {
            negative = true;
        }
        else if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else
        {
            if (negative)
            {
                negatives_numbers.push_back(-num);
            }
            num = 0;
            negative = false;
        }
    }

    if (negative)
    {
        negatives_numbers.push_back(-num);
    }

    if (!negatives_numbers.empty())
    {
        string msg = "negative numbers not allowed ";
        for (size_t i = 0; i < negatives_numbers.size(); ++i)
        {
            msg += to_string(negatives_numbers[i]);
            if (i < negatives_numbers.size() - 1)
            {
                msg += ",";
            }
        }
        throw invalid_argument(msg);
    }
}

vector<string> StringCalculator::getTokens(const string &numbers)
{
    vector<string> delimiters;
    string input = numbers;

    // Handle custom delimiters
    if (numbers.substr(0, 2) == "//")
    {
        size_t pos = numbers.find("\n");
        string delimiter_section = numbers.substr(2, pos - 2);

        if (delimiter_section[0] == '[' && delimiter_section.back() == ']')
        {
            // Multiple delimiters
            size_t start = 0;
            size_t end = delimiter_section.find(']');
            while (end != string::npos)
            {
                delimiters.push_back(delimiter_section.substr(start + 1, end - start - 1));
                start = end + 1;
                end = delimiter_section.find(']', start);
            }
        }
        else
        {
            // Single delimiter
            delimiters.push_back(delimiter_section);
        }
        input = numbers.substr(pos + 1);
    }
    else
    {
        delimiters.push_back(",");
    }
    delimiters.push_back("\n");

    string delimiters_regex;
    for (const auto &delimiter : delimiters)
    {
        if (!delimiters_regex.empty())
        {
            delimiters_regex += "|";
        }
        delimiters_regex += regex_replace(delimiter, regex(R"([.^$|()\\[\]{}*+?])"), R"(\$&)");
    }

    regex re(delimiters_regex);
    sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
    vector<string> tokens{first, last};

    return tokens;
}
