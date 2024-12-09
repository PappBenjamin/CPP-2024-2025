#include "EmailService.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cctype> // isdigit, isalpha
using namespace std;

EmailService::EmailService(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File cannot be opened");
    }

    string userName;
    while (file >> userName) {
        addUsername(userName);
    }
}

void EmailService::addUsername(const string &user)
{

    for (auto &c : user)
    {
        if (isdigit(c)) {
            throw runtime_error("Username cannot contain numbers");
        }
    }

    auto &indices = this->username[user];
    bool added = false;

    // Keress egy üres (0 értékű) helyet
    for (int i = 0; i < indices.size(); ++i)
    {
        if (indices[i] == 0)
        {
            indices[i] = 1; // Használatba vesszük az indexet
            if (i == 0)
            {
                cout << "OK" << endl;
            }
            else {

                cout << user << i << endl;
            }
            added = true;
            break;
        }
    }

    // Ha nem volt üres hely, új indexet adunk hozzá
    if (!added)
    {
        indices.push_back(1);

        if (indices.size() == 1)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << user << indices.size() - 1 << endl;
        }
    }
}

void EmailService::removeUsername(const string &user) {
    string userNameWNR;
    int number = 0;

    for (const auto &c : user) {
        if (isalpha(c)) {
            userNameWNR += c;
        } else if (isdigit(c)) {
            number = number * 10 + (c - '0');
        }
    }

    auto it = this->username.find(userNameWNR);
    if (it == this->username.end()) {
        throw runtime_error("User not found");
    }

    auto &indices = it->second;
    indices[number] = 0; // Felszabadítjuk az indexet
}

void EmailService::showAll() {
    for (const auto &entry : this->username)
    {
        const auto &user = entry.first;
        const auto &indices = entry.second;

        // Kiírjuk az összes érvényes (nem 0) indexet
        for (int i = 0; i < indices.size(); ++i) {
            if (indices[i] != 0)
            {
                if (i == 0)
                {
                    cout << user << " ";
                } else {
                    cout << user << i << " ";
                }
            }
        }
        cout << endl;
    }
}
