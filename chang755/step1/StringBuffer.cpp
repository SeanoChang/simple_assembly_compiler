/* 
Read the input file with "filename"
*/
#include <iostream>

#include "StringBuffer.h"

StringBuffer* StringBuffer::uniqueStrBuffer = NULL;

StringBuffer* StringBuffer::getStringBuffer(){
    static StringBuffer* stringBuffer = new StringBuffer();
    return stringBuffer;
}

std::string StringBuffer::getString() {
    std::string rtv = strBuffer.back();
    strBuffer.pop_back();
    return rtv;
}

void StringBuffer::addString(std::string str) {
    if(strBuffer.size() == strBuffer.capacity()){ // if the buffer is full double the size
        strBuffer.reserve(strBuffer.capacity() * 2);
    }
    strBuffer.push_back(str);
}