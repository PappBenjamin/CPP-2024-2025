
#ifndef LAB12_SIMPLETEXTGENERATOR_H
#define LAB12_SIMPLETEXTGENERATOR_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "TextGenerator.h"

using namespace std;



class SimpleTextGenerator: public TextGenerator {

    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};

#endif //LAB12_SIMPLETEXTGENERATOR_H
