#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP
#include<vector>
#include <string>
 using namespace std;
class StringCalculator {
public:
    static int add(const string& numbers);
    static void CheckNagtive(const string &numbers);

    static vector<string> getTokens(const string &numbers);
};

#endif // STRING_CALCULATOR_HPP