#include "point.h"
using namespace std;

point::point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}

int point::getX() const {
    return x;
}

int point::getY() const {
    return y;
}

void point::print(const string &prefix, const string &suffix) const {
    cout << prefix << "(" << x << ", " << y << ")" << suffix;
}

double distance(const point &a, const point &b)
{
    double hosszx = b.getX() - a.getX();
    double hosszy = b.getY() - a.getY();

    double final = sqrt( pow(hosszx,2) + pow(hosszy,2) );

    return final;
}

bool isSquare(const point &a, const point &b, const point &c, const point &d) {

    set<int> s;

    double distO1 = distance(a,b);
    double distO2 = distance(b,c);
    double distO3 = distance(c,d);

    s.insert(distO1);
    s.insert(distO2);
    s.insert(distO3);

    if (s.size() == 2)
    {
        return true;
    }
        return false;
}

point *createArray(int numPoints)
{
    point* array = new point[numPoints];

    random_device rd;
    uniform_int_distribution<int> dist(0, 2000);

    for(int i = 0; i < numPoints; ++i)
    {
        point temp(dist(rd), dist(rd));
        array[i] = temp;
    }

    return array;
}


