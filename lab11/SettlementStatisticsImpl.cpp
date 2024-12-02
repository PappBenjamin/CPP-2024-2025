#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &filename)
{
    ifstream file(filename);
    if(file.is_open())
    {


        while(!file.eof())
        {
            string line;
            getline(file, line);


            istringstream lineStream(line);
            string line1;
            getline(lineStream, line1, ',');
            string line2;
            getline(lineStream, line2, ',');

            int integer;
            lineStream >> integer;


            Settlement s(line1, line2, integer);
            auto mypair = make_pair(line2, s);
            this->settlements.insert(mypair);
        }
    }
    else
    {
        throw runtime_error("File not found");
    }




}

int SettlementStatisticsImpl::numSettlements() const
{
    return this->settlements.size();
}
int SettlementStatisticsImpl::numCounties() const
{
    set<string> counties;
    for(auto it = this->settlements.begin(); it != this->settlements.end(); it++)
    {
        counties.insert(it->second.getCounty());
    }
    return counties.size();
}
int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const
{
   return this->settlements.count(county);
}
vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {

    vector<Settlement> temp;

    for(auto it = this->settlements.begin(); it != this->settlements.end(); it++)
    {
        if(it->second.getCounty() == county)
        {
            temp.push_back(it->second);
        }
    }

    return temp;
}
Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const
{
    vector<Settlement> temp = findSettlementsByCounty(county);

    for(auto it = temp.begin(); it != temp.end(); it++)
    {
        if(it->getName() == name)
        {
            return *it;
        }
    }

    throw runtime_error("Settlement not found");
}
Settlement SettlementStatisticsImpl::maxPopulation() const {

    Settlement max;
    for(auto it = this->settlements.begin(); it != this->settlements.end(); it++)
    {
        if(it->second.getPopulation() > max.getPopulation())
        {
            max = it->second;
        }
    }

    return max;
}
Settlement SettlementStatisticsImpl::minPopulation() const {

    Settlement min;
    for(auto it = this->settlements.begin(); it != this->settlements.end(); it++)
    {
        if(it->second.getPopulation() < min.getPopulation())
        {
            min = it->second;
        }
    }

    return min;
}
vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name){
    return vector<Settlement>();
}



