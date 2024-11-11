#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

int main() {
    // Vector of fruits
    vector<string> fruits {"melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"};

    // Find the first fruit that contains "al"
    auto one = find_if(fruits.begin(), fruits.end(), [](string &s) { return s.find("al") != string::npos; });
    cout << "Searched word: " << *one << endl;

    // Vector of numbers
    vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Check if all numbers are even (not used, but example remains)
    bool allEven = all_of(numbers.begin(), numbers.end(), [](int number) { return number % 2 == 0; });

    // Double each number
    for_each(numbers.begin(), numbers.end(), [](int &number) { number *= 2; });
    cout << "Doubled numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int number) { cout << number << " "; });
    cout << endl;

    // Vector of months
    vector<string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Count months with 5 letters
    int countFiveLetterMonths = count_if(months.begin(), months.end(), [](const string &month) { return month.length() == 5; });
    cout << "Number of months with 5 letters: " << countFiveLetterMonths << endl;

    // Sort numbers in descending order
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "Sorted numbers v1 / v2: ";
    for_each(numbers.begin(), numbers.end(), [](int number) { cout << number << " "; });
    cout << endl;

    // Vector of month-temperature pairs
    vector<pair<string, double>> tempsForMonths {
            {"January", 1.4}, {"February", 2.4}, {"March", 3.4}, {"April", 4.4},
            {"May", 5.4}, {"June", 6.4}, {"July", 7.4}, {"August", 8.4},
            {"September", 9.4}, {"October", 10.4}, {"November", 11.4}, {"December", 12.4}
    };

    // Sort temperatures for months in ascending order
    sort(tempsForMonths.begin(), tempsForMonths.end(), [](const pair<string, double> &a, const pair<string, double> &b) {
        return a.second < b.second;
    });
    cout << "Sorted temps: ";
    for_each(tempsForMonths.begin(), tempsForMonths.end(), [](const pair<string, double> &pair) {
        cout << pair.first << " " << pair.second << " ";
    });
    cout << endl;

    // Convert months to lowercase
    for_each(months.begin(), months.end(), [](string &month) {
        transform(month.begin(), month.end(), month.begin(), ::tolower);
    });
    cout << "Months in lowercase: ";
    for_each(months.begin(), months.end(), [](const string &month)
    {
        cout << month << " ";
    });
    cout << endl;

    //abc
    cout << "shuffled ABC: ";
    vector<char> abc;
    for(auto c='a'; c <= 'z'; c++)
    {
        abc.push_back(c);
    }
    shuffle(abc.begin(), abc.end(), mt19937(random_device()()));

    for(int i = 0; i < abc.size(); i++)
    {
        cout << abc[i] << " ";
    }

    sort(months.begin(), months.end(),[&abc](string & s1, string &s2){
       auto it = find(abc.begin(), abc.end(), s1[0]);
       auto it2 = find(abc.begin(), abc.end(), s2[0]);
       return it < it2;
    });

    cout << endl;
    cout << "Months in order: ";
    for_each(months.begin(), months.end(), [](const string &month)
    {
        cout << month << " ";
    });
    cout << endl;







    return 0;
}
