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
        return (numbers[0]-'0');
    
   
    string duplicate_input=numbers;
    int sum = 0;
    int num = 0;
    bool negative = false;
    char delimiter = ','; 
    
    // handle custom delimiter
     if (numbers.find("//") == 0) {
        size_t pos = numbers.find("\n");
        delimiter = numbers[2]; 
        duplicate_input = numbers.substr(pos + 1);
    }
    
    for (char c : duplicate_input) {
        if (c == '-') {
            negative = true;
        } else if (c == delimiter || c=='\n') {
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