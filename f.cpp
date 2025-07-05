#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;

string f(string date){
    // Store month days
    unordered_map<int,int> months = {
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 31},
        {5, 31},
        {6, 31},
        {7, 31},
        {8, 31},
        {9, 31},
        {10, 31},
        {11, 31},
        {12, 31},
    };
    // Extract date values as int
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    // Divide year by 100 and subtract year divide 400 - 1
    int adjust = (year / 100) - (year / 400) - 1;
    // Add result to day, incrementing months according to overflow
    day += adjust;
    // Increment month for day overflow
    while(day > months[month]){     
        // Adjust for Febuary leap years
        if(month == 2 && !(year % 4) && !(year % 100)) day --;
        day -= months[month];
        month++;
    }
    // Increment year for year overflow
    if(month > 12){
        year++;
        month = month - 12;
    }
    // Rebuild date into string
    string syear = to_string(year);
    string smonth = to_string(month);
    string sday = to_string(day);
    if(smonth.length() < 2) smonth = '0' + smonth;
    if(sday.length() < 2) sday = '0' + sday;
    return syear + '-' + smonth + '-' + sday;
}
int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string date;
        getline(cin, date);
        cout << f(date) << endl;
    }

    return 0;
}