#ifndef LAB12_TEXTGENERATOR_H
#define LAB12_TEXTGENERATOR_H

#include <string>
#include <map>

using namespace std;


class TextGenerator {
    public:
        virtual void trainFromText(string trainingText) = 0;
        virtual void trainFromFile(string filename) = 0;
        virtual string generate(string startWords, int numWords=10) = 0;
        //virtual~TextGenerator() = default;
};

#endif //LAB12_TEXTGENERATOR_H
