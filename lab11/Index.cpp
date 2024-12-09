#include "Index.h"

Index::Index(const string &filename)
{

    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        int count = 0; // sorok szama

        while (getline(file, line))
        {
            count++;
            istringstream iss(line);

            while(iss >> line)
            {
                line.erase( remove_if(line.begin(), line.end(), [](char x) {
                    return !isalnum(x) && !isspace(x);
                }) , line.end() );

                if(std::find(indexMap[line].begin(), indexMap[line].end(), count) == indexMap[line].end())
                {
                    indexMap[line].push_back(count);
                }
            }

        }
    }
}

vector<int> Index::search(const string &word) {

    if (indexMap.find(word) == indexMap.end())
    {
        throw invalid_argument("Word not found");
    }

    return indexMap[word];
}
