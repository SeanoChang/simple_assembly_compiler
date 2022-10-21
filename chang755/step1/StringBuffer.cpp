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