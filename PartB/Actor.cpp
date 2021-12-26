// Berdan Akyurek
//21600904
//CS201 HW1

#include "Actor.h"
// using namespace std;

// Constructor for Actor
Actor::Actor(const string aName, const string aBirthPlace, const unsigned int aBirthYear )
{
    name = aName;
    birthPlace = aBirthPlace;
    birthYear = aBirthYear;
}

// Copy constructor for Actor
Actor::Actor(const Actor &actorToCopy)
{
    name = actorToCopy.name;
    birthPlace = actorToCopy.birthPlace;
    birthYear = actorToCopy.birthYear;
}

// Destructor
Actor::~Actor()
{

}

// Assignment operator
void Actor::operator=(const Actor &right)
{
    name = right.name;
    birthPlace = right.birthPlace;
    birthYear = right.birthYear;
}

// Get functions
string Actor::getName() const
{
    return name;
}

string Actor::getBirthPlace() const
{
    return birthPlace;
}

unsigned int Actor::getBirthYear() const
{
    return birthYear;
}

// << operator overloading
ostream& operator<<(ostream& out, const Actor& a)
{
    out << a.name << ", " << a.birthPlace << ", " << a.birthYear;
    return out;
}

