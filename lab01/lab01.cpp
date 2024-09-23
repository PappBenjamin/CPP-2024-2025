#include "lab01.h"


int countBits(int nb)
{
    int count = 0;

    for(count;nb;nb >>= 1 )
    {
        count += nb & 1;
    }
    return count;
}

bool modifyBits(int& nb, int order)
{
    if(order >= 1 && order <= 31)
    {
        nb = nb | 1 << order;
        return true;
    }
    return false;
}

double mean(double *array, int numElements)
{

    if(!numElements)
    {
        return NAN;
    }

    double mean = 0;

   for(int i = 0; i < numElements; ++i)
   {
        mean += array[i];
   }

   return mean / numElements;

}

double stddev(double *array, int numElements)
{
    double mean1 = mean(array,numElements);
    double dev = 0;

    for(int i = 0; i < numElements; ++i)
    {
        dev += pow(array[i] - mean1,2);
    }

    return sqrt(dev / 10);
}

pair<double, double> max(double *array, int numElements)
{
    sort(array,array+numElements,greater<double>());

    return make_pair(array[1],array[0]);
}

//--------------------------------------------------------------

void stringOne(istringstream & text) {
    string temp;
    double cnt = 0;

    while(text >> temp)
    {
        istringstream tempstream(temp);
        double nb;

        if(tempstream >> nb)
        {
            cnt += nb;
        }
    }

    cout << cnt;
}

int countWords(string text){

    int count = 0;
    istringstream words(text);

    while(words >> text)
    {
        count++;
    }

    return count;
}

string code(string text) {
    string final;
    for(int i = 0; i < text.length(); ++i)
    {
        if(isascii(text[i]) && !isdigit(text[i]))
        {
            final += char( (int)text[i] + 1);
            continue;
        }

        final += text[i];
    }
    return final;
}

string decode(string text)
{
    string final;
    for(int i = 0; i < text.length(); ++i)
    {
        if(isascii(text[i]) && !isdigit(text[i]))
        {
            final += char( (int)text[i] + -1);
            continue;
        }

        final += text[i];
    }
    return final;
}

string capitalizeWords(string text)
{
    string final;

    string temp2;
    istringstream temp(text);

    while(temp >> temp2)
    {
        for(int i = 0;i < temp2.length(); ++i)
        {
            if(!isascii(temp2[i]))
            {
                return "error";
            }

            if(i == 0){final += toupper(temp2[i]); continue;}

            final += tolower(temp2[i]);
        }

        final += " ";
    }


    return final;
}