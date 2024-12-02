
#ifndef LAB11_SETTLEMENT_H
#define LAB11_SETTLEMENT_H

#include <iostream>
#include <string>

using namespace std;


class Settlement {
    string name;
    string county;
    int population;

public:
    Settlement() = default;
    Settlement(string name, string county, int population);

// constructor, getters, setters, inserter operator
    const string &getName() const;
    void setName(const string &name);

    const string &getCounty() const;
    void setCounty(const string &county);

    int getPopulation() const;
    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const Settlement &settlement);

};


#endif //LAB11_SETTLEMENT_H
