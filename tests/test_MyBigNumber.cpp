#include <iostream>
#include <string>
#include <vector>
#include "../src/MyBigNumber.h"

struct TestResult
{
    std::string name;
    bool passed;
    std::string expected;
    std::string actual;
};

std::vector<TestResult> results;
int passed = 0, failed = 0;

void assertEqual(const std::string &testName,
                 const std::string &expected,
                 const std::string &actual)
{
    bool ok = (expected == actual);
    results.push_back({testName, ok, expected, actual});
    if (ok)
    {
        ++passed;
        std::cout << "  [PASS] " << testName << "\n";
    }
    else
    {
        ++failed;
        std::cout << "  [FAIL] " << testName
                  << "\n         expected: \"" << expected << "\""
                  << "\n         actual  : \"" << actual << "\"\n";
    }
}

// ============================================================
// Test cases
// ============================================================
void runTests()
{
    std::cout << "\n========== UNIT TESTS: MyBigNumber::sum() ==========\n\n";

    assertEqual("TC01 - Ví dụ đề bài: 1234 + 897",
                "2131", MyBigNumber::sum("1234", "897"));

    assertEqual("TC02 - Số bằng nhau: 500 + 500",
                "1000", MyBigNumber::sum("500", "500"));

    assertEqual("TC03 - Cộng với 0: 12345 + 0",
                "12345", MyBigNumber::sum("12345", "0"));

    assertEqual("TC04 - Cả hai bằng 0: 0 + 0",
                "0", MyBigNumber::sum("0", "0"));

    assertEqual("TC05 - Nhớ liên tiếp: 999 + 1",
                "1000", MyBigNumber::sum("999", "1"));

    assertEqual("TC06 - Số rất lớn",
                "99999999999999999999999999999",
                MyBigNumber::sum("99999999999999999999999999998", "1"));

    assertEqual("TC07 - Hai số lớn",
                "1111111110111111111011111111100",
                MyBigNumber::sum(
                    "123456789012345678901234567890",
                    "987654321098765432109876543210"));

    assertEqual("TC08 - stn1 ngắn hơn: 5 + 9999",
                "10004", MyBigNumber::sum("5", "9999"));

    assertEqual("TC09 - stn2 ngắn hơn: 9999 + 5",
                "10004", MyBigNumber::sum("9999", "5"));

    assertEqual("TC10 - Một chữ số: 7 + 8",
                "15", MyBigNumber::sum("7", "8"));

    assertEqual("TC11 - Không sinh nhớ: 123 + 456",
                "579", MyBigNumber::sum("123", "456"));

    assertEqual("TC12 - 1 + 1",
                "2", MyBigNumber::sum("1", "1"));
}

// ============================================================
// Summary
// ============================================================
void printSummary()
{
    std::cout << "\n====================================================\n";
    std::cout << "KẾT QUẢ: " << passed << " PASS / "
              << failed << " FAIL / "
              << (passed + failed) << " TỔNG\n";
    std::cout << "====================================================\n\n";
}

int main()
{
    runTests();
    printSummary();
    return (failed > 0) ? 1 : 0;
}