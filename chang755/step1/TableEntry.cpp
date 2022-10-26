#include <iostream>
#include <string>

#include "TableEntry.h"


/* constructor */
TableEntry::TableEntry() {
}

TableEntry::TableEntry(long _location, long _length){
    location = _location;
    length = _length;
}

int TableEntry::getLocation() const {
    return location;
}

int TableEntry::getLength() const {
    return length;
}
