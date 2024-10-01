#include <iostream>
#include "point.h"

using namespace std;
int main(int argc, char** argv)
{
    point p1(1,1);
    p1.print("p1","\n");

    point p2(4, 5);
    cout<<"p2( "<<p2.getX()<<" , "<<p2.getY()<<")"<<endl;

    point * pp1 = new point(300, 400);
    point * pp2 = new point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<" , "<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<" , "<<pp2->getY()<<")"<<endl;

    delete pp1;
    delete pp2;

    ////////////////////////////////////////////////////////////////

    cout << "Distance: " <<  distance(p1,p2) << endl;

    // cout << isSquare(p1,p2,*pp1,*pp2);

    point*points = createArray(500);
    pair<point,point> minPoints = closestpoints(points,500);

    cout<<"The closest points are: ("<<minPoints.first.getX()<<","<< minPoints.first.getY() <<") and ("<<minPoints.second.getX()<<","<<minPoints.second.getY()<<")"<<endl;

    sortPoints(points,500);
}