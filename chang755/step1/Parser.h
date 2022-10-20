/*
The parser.cpp is where all the parsing happens. 
It is the main class that calls all the other classes.
*/

#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <string>

class Parser {
    public:
        Parser();
        ~Parser();
        void parse(std::string);
    private:
        std::string line;
};

#endif /* PARSER_H_ */

