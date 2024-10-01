#ifndef LAB2_point_H
#define LAB2_point_H

#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <random>
using namespace std;


class point{

private:
    int x, y;
public:
    explicit point( int x=0, int y=0);

    int getX() const;
    int getY() const;
    void print(const string &prefix, const string &suffix) const;
};

double distance(const point& a, const point& b);

bool isSquare(const point& a, const point& b, const point& c, const point& d);

point* createArray(int numpoints);

pair<point, point> closestpoints(point* points, int numpoints);

bool cmp2( point& a,point& b);
void sortPoints(point* points, int numpoints);
#endif //LAB2_point_H
