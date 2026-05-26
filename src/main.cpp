#include <iostream>
#include <vector>
#include "MyBigNumber.h"

int main() {
    cout << "=== Add2Num: Cộng 2 số lớn ===\n\n";
    vector<pair<string,string>> testCases = {
        {"1234",  "897"},
        {"999",   "1"},
        {"0",     "0"},
        {"99999999999999999999", "1"},
        {"123456789012345678901234567890",
         "987654321098765432109876543210"}
    };

    for (auto& [a, b] : testCases) {
        string result = MyBigNumber::sum(a, b);
        cout << "  " << a << " + " << b << " = " << result << "\n\n";
    }

    return 0;
}