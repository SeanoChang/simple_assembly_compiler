/* 
Read the input file with "filename"
*/
#include <iostream>

#include "StringBuffer.h"

StringBuffer* StringBuffer::uniqueStrBuffer = NULL;
std::vector<std::string> StringBuffer::strBuffer = std::vector<std::string>();

/* constructor destructor */
StringBuffer::StringBuffer(){
    strBuffer.reserve(10);
}

StringBuffer::~StringBuffer(){
    delete uniqueStrBuffer;
}

/* singleton getInstance method */
StringBuffer* StringBuffer::getStringBuffer(){
    if(uniqueStrBuffer == NULL){
        uniqueStrBuffer = new StringBuffer();
    }
    return uniqueStrBuffer;
}

/* get the string */
std::string StringBuffer::getString(int index) {
    return strBuffer[index];
}

/* add the string to the buffer and return the position added in the buffer*/
int StringBuffer::addString(std::string str) {
    if(strBuffer.size() == strBuffer.capacity()){ // if the buffer is full double the size
        strBuffer.reserve(strBuffer.capacity() * 2);
    }
    strBuffer.push_back(str);

    return strBuffer.size() - 1;
}