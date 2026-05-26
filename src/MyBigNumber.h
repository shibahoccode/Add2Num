#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

class MyBigNumber {
public:
    static string sum(const string& stn1, const string& stn2);

private:
    static void log(const string& message);
    static string getCurrentTime();
};