#ifndef STRINGBUFFER_H
#define STRINGBUFFER_H
#include <iostream>
#include <string>
#include <vector>

/*
String buffer class is used to store the string from the input file.
*/
class StringBuffer{
    public:
        static StringBuffer* getStringBuffer();
        ~StringBuffer();
        std::string getString(int index);
        int addString(std::string str);
    private:
        static StringBuffer* uniqueStrBuffer;
        static std::vector<std::string> strBuffer;
        StringBuffer();
};

#endif 
