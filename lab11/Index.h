#ifndef LAB11_INDEX_H
#define LAB11_INDEX_H

#include <iostream>
#include <string>
#include <map>

//for reading
#include <fstream>
#include <sstream>

using namespace std;


class Index {

private:
    map<string, vector<int>> indexMap;

public:
    Index(const string &filename);
    vector<int> search(const string &word);

};


#endif //LAB11_INDEX_H
