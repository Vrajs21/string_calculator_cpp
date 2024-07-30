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
        

}