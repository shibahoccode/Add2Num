#include "MyBigNumber.h"
#include <algorithm>

// ============================================================
// LOGGING
// ============================================================

string MyBigNumber::getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return string(buf);
}

void MyBigNumber::log(const string& message) {
    string entry = "[" + getCurrentTime() + "] " + message;
    cout << entry << endl;
    ofstream logFile("add2num.log", ios::app);
    if (logFile.is_open()) {
        logFile << entry << "\n";
    }
}
// ============================================================
// CORE ALGORITHM
// ============================================================

string MyBigNumber::sum(const string& stn1, const string& stn2) {
    log("=== BẮT ĐẦU PHÉP CỘNG ===");
    log("Số thứ nhất : \"" + stn1 + "\"");
    log("Số thứ hai  : \"" + stn2 + "\"");

    string result = "";
    int carry = 0;
    int i = (int)stn1.size() - 1;  
    int j = (int)stn2.size() - 1;  
    int step = 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1  = (i >= 0) ? (stn1[i] - '0') : 0;
        int digit2  = (j >= 0) ? (stn2[j] - '0') : 0;
        int carry_in = carry;    
        int total        = digit1 + digit2 + carry_in;
        int currentDigit = total % 10;
        carry            = total / 10;  

        result = to_string(currentDigit) + result;
        string stepLog = "Bước " + to_string(step) + ": "
            + to_string(digit1) + " + " + to_string(digit2)
            + " + nhớ_vào(" + to_string(carry_in) + ")"
            + " = " + to_string(total)
            + "  →  lưu " + to_string(currentDigit)
            + ", nhớ " + to_string(carry)
            + "  →  kết quả tạm: \"" + result + "\"";
        log(stepLog);
        i--;
        j--;
        step++;
    }

    if (result.empty()) result = "0";
    log("Kết quả cuối: \"" + result + "\"");
    log("=== KẾT THÚC PHÉP CỘNG ===\n");
    return result;
}