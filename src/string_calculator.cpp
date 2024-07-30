#include "../include/string_calculator.hpp"
#include<bits/stdc++.h>
#include <algorithm> 
#include <cctype> 
using namespace std;

int StringCalculator::add(const string& numbers) {
    
    if (numbers.empty()) {
        return 0;
    }

    if(numbers.length()==1 && isdigit(numbers[0]))
        return stoi(numbers.substr(0));
    
   

    int sum = 0;
    int num = 0;
    bool negative = false;
    
    for (char c : numbers) {
        if (c == '-') {
            negative = true;
        } else if (c == ',' || c=='\n') {
            sum += negative ? -num : num;
            num = 0;
            negative = false;
        } else {
            num = num * 10 + (c - '0');
        }
    }

    sum += negative ? -num : num;

    return sum;
}