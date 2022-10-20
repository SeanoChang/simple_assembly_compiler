#ifndef STRINGBUFFER_H
#define STRINGBUFFER_H
#include <iostream>
#include <string>

/*
String buffer class is used to store the string from the input file.
*/
class StringBuffer{
    public:
        StringBuffer();
        ~StringBuffer();
        std::string getString();
        void setString(std::string str);
    private:
        std::string buffer;
};

#endif 
