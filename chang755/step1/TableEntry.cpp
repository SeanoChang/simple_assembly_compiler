#include <iostream>
#include <string>

#include "TableEntry.h"


/* constructor */
TableEntry::TableEntry() {
}

TableEntry::TableEntry(std::string symbol, long location, long length){
    this->symbol = symbol;
    this->location = location;
    this->length = length;
}

/* destructor */
TableEntry::~TableEntry(){
    delete this;
}
