#include "PointSet.h"


void PointSet::computeDistances()
{
  for(int i = 0; i < points.size(); ++i)
  {
      for(int j = i + 1; j < points.size(); ++j)
      {
          distances.push_back(points[i].distanceTo(points[j]));
      }
  }
//  cout << "#distances: " <<distances.size() << endl;
}


PointSet::PointSet(int n)
{
    this->n = n;
    bool exist[M + 1][M + 1] = {false};


    while(points.size() != n)
    {
        int x = random() % M + 1;
        int y = random() % M + 1;

        if(!exist[x][y])
        {
            points.push_back(Point(x,y));
            exist[x][y] = true;
        }
    }
    computeDistances();
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(),distances.end());
}

int PointSet::numDistances() const
{
    return distances.size();
}

void PointSet::printPoints() const {
    for(auto i: points)
    {
        cout << "(" << i.getX() << "," << i.getY() << ")" << endl;
    }

}

bool cmpX(Point a, Point b)
{
    return a.getX() < b.getX();
}

void PointSet::sortPointsX()
{
    sort(points.begin(), points.end(),cmpX);
}

bool cmpY(Point a, Point b)
{
    return a.getY() < b.getY();
}

void PointSet::sortPointsY()
{
    sort(points.begin(), points.end(), cmpY);
}


bool cmp(double a, double b)
{
    return a < b;
}

void PointSet::sortDistances()
{
    sort(distances.begin(),distances.end(),cmp);
}

int PointSet::numDistinctDistances()
{
    set<double> s;

    for(auto i:distances)
    {
        s.insert(i);
    }

    return s.size();
}

void PointSet::printDistances() const
{

    for(auto i: distances)
    {
        cout  << i << ", ";
    }

    cout << endl;

}


