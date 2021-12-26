// Berdan Akyurek
// 21600904

#include "Author.h"
#include <iostream>

Author::Author()
{
    id = 0;
    name = "";
}

Author::Author(const int idA, const string nameA)
{
    id = idA;
    name = nameA;
    
}

int Author::getID() const
{
    return id;
}

void Author::setID(const int idA)
{
    id = idA;
}

string Author::getName() const
{
    return name;
}

void Author::setName(const string id)
{
    name = id;
}