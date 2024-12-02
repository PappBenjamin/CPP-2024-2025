#include "Settlement.h"

const string &Settlement::getName() const {
    return name;
}
void Settlement::setName(const string &name) {
    Settlement::name = name;
}

const string &Settlement::getCounty() const {
    return county;
}
void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

int Settlement::getPopulation() const {
    return population;
}
void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

Settlement::Settlement(string name, string county, int population) {
    this->name = name;
    this->county = county;
    this->population = population;
}

ostream &operator<<(ostream &os, const Settlement &settlement)
{
    os << "Name: " << settlement.name << " Settlement: " << settlement.county << " Population: " << settlement.population;
    return os;
}
