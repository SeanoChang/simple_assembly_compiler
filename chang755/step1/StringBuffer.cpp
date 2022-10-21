/* 
Read the input file with "filename"
*/
#include <iostream>

#include "StringBuffer.h"

StringBuffer::StringBuffer(std::string str) {
    this->strBuffer = str;
}

StringBuffer::~StringBuffer() {
    delete this;
}

std::string StringBuffer::getString() {
    return this->strBuffer;
}

void StringBuffer::setString(std::string str) {
    this->strBuffer = str;
}