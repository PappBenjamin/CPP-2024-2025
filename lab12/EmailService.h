#ifndef LAB12_EMAILSERVICE_H
#define LAB12_EMAILSERVICE_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector> // Include vector header

using namespace std;

class EmailService {

private:
    map<string, vector<int>> username;  // Using map to store usernames and their instances

public:
    // Default constructor
    EmailService() = default;

    // Constructor that loads users from a file
    EmailService(const string& filename);

    // Adds a username
    void addUsername(const string& user);

    // Removes a username based on its specific instance
    void removeUsername(const string& user);

    // Displays all users and their instances
    void showAll();
};

#endif // LAB12_EMAILSERVICE_H
