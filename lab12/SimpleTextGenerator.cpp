//
// Created by Macbook on 09.12.2024.
//

#include "SimpleTextGenerator.h"

void SimpleTextGenerator::trainFromText(string trainingText)
{
    istringstream iss(trainingText);

    string word1;
    string cleanWord1;
    vector <string> words;

    //Clean the text
    while (iss >> word1)
    {
        for(int i = 0; i < word1.length(); i++)
        {
            word1[i] = tolower(word1[i]);

            if (isalnum(word1[i]))
            {
                cleanWord1 += word1[i];
            }
        }


        words.push_back(cleanWord1);
        cleanWord1.clear();

    }


    for (int i = 0; i < words.size() - 1; i++)
    {
        string key = words[i] + " " + words[i + 1];

        auto it = this->data.find(key);

        if(it == this->data.end())
        {
            this->data[key].push_back(words[i + 2]);
        }
        else
        {
            auto & v = it->second;
            auto it2 = find(v.begin(), v.end(), words[i + 2]);

            if(it2 == v.end())
            {
                v.push_back(words[i + 2]);
            }
        }

    }


}

void SimpleTextGenerator::printData() const
{

   for(const auto &data: this->data)
   {
       cout << data.first << ": ";

       for(auto value: data.second)
       {
           cout << value << " ";
       }

       cout << endl;
   }

}

void SimpleTextGenerator::trainFromFile(string filename)
{

    string line;
    ifstream file(filename);

    while (getline(file, line))
    {
        this->trainFromText(line);
    }

}

string SimpleTextGenerator::generate(string startWords, int numWords)
{

    string result = startWords;
    string key = startWords;


    for(int i = 0; i < numWords; i++)
    {
        auto it = this->data.find(key);
        if(it == this->data.end())
        {
            return result;
        }

        int randomValue = rand();
        int size = it->second.size();

        int randomNB = randomValue % size;



        result += " " + this->data[key][randomNB];
        key = key.substr(key.find(" ") + 1) + " " + this->data[key][randomNB];

    }

    return result;

}
