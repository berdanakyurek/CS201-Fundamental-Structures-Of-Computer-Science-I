// Berdan Akyurek
//21600904
//CS201 HW1

#include "SimpleFilm.h"
#include <string>
using namespace std;
#include <iostream>

// Constructor for Film object
Film::Film(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration)
{
    title = fTitle;
    director = fDirector;
    year = fYear;
    duration = fDuration;
}
// Copy constructor for Film Object
Film::Film(const Film &fToCopy)
{
    title = fToCopy.title;
    director = fToCopy.director;
    year = fToCopy.year;
    duration = fToCopy.duration;
}

// Destructor for Film object
Film::~Film()
{
}

// Overloading = operator 

void Film::operator=( const Film &right)
{
    title = right.title;
    director = right.director;
    year = right.year;
    duration = right.duration;
}

//Get Functions

string Film::getTitle() const
{
    return title;
}

string Film::getDirector() const
{
    return director;
}

unsigned int Film::getYear() const
{
    return year;
}

unsigned int Film::getDuration() const
{
    return duration;
}

// Overloading << operator
ostream& operator<<(ostream& out, const Film& f)
{
    out << f.getTitle() <<", "<< f.getYear() << ", " << f.getDirector() << ", " << f.getDuration() << " min"<< endl;
    return out;
}