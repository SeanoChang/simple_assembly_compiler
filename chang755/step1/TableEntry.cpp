#include <iostream>
#include <string>

#include "TableEntry.h"


/* constructor */
TableEntry::TableEntry(){
    
}

/* destructor */
TableEntry::~TableEntry(){
    delete this;
}

/* method for deleting the entire stack */
void TableEntry::deleteTableEntry(){
    TableEntry* temp = top;
    while(temp != NULL){
        top = top->next;
        delete temp;
        temp = top;
    }
}

/* pushing the new symbol up to the table entry */
void TableEntry::push(std::string symbol, int location, int length){
    TableEntry* newEntry = new TableEntry();
    newEntry->symbol = symbol;
    newEntry->location = location;
    newEntry->length = length;
    newEntry->next = top;
    top = newEntry;
}

/* popping the symbol off te table entry */
void TableEntry::pop(){
    TableEntry* temp = top;
    top = top->next;
    delete temp;
}
