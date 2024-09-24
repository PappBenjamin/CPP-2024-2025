#include "extra.h"

void printNWord(string &fileName, int n)
{

    map<string, int> bibleWords;
    string word;

    ifstream bible(fileName);

    while(bible >> word)
    {
        transform(word.begin(), word.end(), word.begin(),::tolower);

        for(int i = 0; i <= word.length(); ++i)
        {
            if(!isalpha(word[i])){word.erase(i, 1);}
        }
        bibleWords[word]++;
    }

    vector< pair<string, int> > bibleWordsVector(bibleWords.begin(), bibleWords.end());
    sort(bibleWordsVector.begin(), bibleWordsVector.end(), compare);

    for (int i = 0; i < bibleWordsVector.size(); ++i)
    {
        cout << bibleWordsVector[i].first << endl;
    }


    cout << "Your " << n << "th common word was: " << bibleWordsVector[n].first << " (" << bibleWordsVector[n].second <<")";

}

bool compare(pair <string, int> a, pair <string, int> b)
{
    if(a.second > b.second){return true;}
    if(a.second < b.second){return false;}
}
