#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#ifndef LAB1_LAB01_H
#define LAB1_LAB01_H

int countBits(int nb); // 1
bool modifyBits(int& nb, int order); // 2
double mean(double array[], int numElements); // 3
double stddev(double array[], int numElements); // 4
pair<double, double> max(double array[], int numElements); // 5

void stringOne(istringstream & text); // 1
int countWords(string text); // 2
string code(string text); // 3
string decode(string text); // 3.1
string capitalizeWords(string text); // 4







#endif //LAB1_LAB01_H
