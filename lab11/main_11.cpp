#include <iostream>
#include "SettlementStatisticsImpl.h"
#include "Index.h"

using namespace std;

int main()
{

//    SettlementStatisticsImpl stat("in.txt");
//
//    cout << "Number of Settlements: " << stat.numSettlements() << endl;
//    cout << "Number of Counties: " << stat.numCounties() << endl;
//    cout << "Maximum population: \n\t" << stat.maxPopulation() << endl;



    Index index("index.txt");
    vector<int> res = index.search("of");

    for(auto i : res)
    {
        cout << i << " ";
    }


}


