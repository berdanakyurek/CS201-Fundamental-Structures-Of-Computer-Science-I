// Berdan Akyurek
//21600904
//CS201 HW1

#include "Film.h"

using namespace std;

// Constructor
Film::Film(const string fTitle, const string fDirector, const unsigned int fYear,const unsigned int fDuration)
{
    title = fTitle;
    director = fDirector;
    year = fYear;
    duration = fDuration;
    noOfActors = 0;
    size = 0;

    actors = NULL;
}
// Copy Constructor
Film::Film(const Film &fToCopy)
{
    title = fToCopy.title;
    director = fToCopy.director;
    year = fToCopy.year;
    duration = fToCopy.duration;
    noOfActors = fToCopy.noOfActors;
    size = fToCopy.size;
    
    actors = new Actor[size];
    for( unsigned int i = 0; i < noOfActors ; i ++ )
        actors[i] = fToCopy.actors[i];
}

// Destructor
Film::~Film()
{
    delete[] actors;
}

// Assignment operator
void Film::operator=(const Film &right)
{
    title = right.title;
    director = right.director;
    year = right.year;
    duration = right.duration;
    noOfActors = right.noOfActors;
    size = right.size;
    delete[] actors;

    actors = new Actor[size];
    for( unsigned int i = 0; i < noOfActors ; i ++ )
        actors[i] = right.actors[i];
}

// get functions

string Film::getFilmTitle() const
{
    return title;
}
string Film::getFilmDirector() const
{
    return director;
}
unsigned int Film::getFilmYear() const
{
    return year;
}
unsigned int Film::getFilmDuration() const
{
    return duration;
}

// Average
unsigned int Film::calculateAverageActorAge() const
{
    if( noOfActors == 0 )
        return 0;

    //const unsigned int currentYear = 2019;
    unsigned int sum = 0;

    for( unsigned int i = 0 ; i < noOfActors ; i ++)
        sum += year - (actors[i].getBirthYear());
    
    return sum/noOfActors;
}

// << operator
ostream& operator<<(ostream& out, const Film& f)
{
    out << f.getFilmTitle() << ", " << f.getFilmDirector() << ", " << f.getFilmYear() << ", " << f.getFilmDuration() << endl;

    for( unsigned int i = 0 ; i < f.noOfActors ; i ++ )
        out << "    " << f.actors[i] << endl;

    return out;
}

// Add a new actor to Film
bool Film::addActor( const string aName, const string aBirthPlace, const unsigned int aBirthYear )
{
    for( unsigned int i = 0 ; i < noOfActors ; i ++ )
    {
        if( actors[i].getName() == aName )
            return false;
    }

    Actor newActor( aName, aBirthPlace, aBirthYear );

    if( size > noOfActors )
    {
        actors[noOfActors] = newActor;
        noOfActors ++;
        return true;
    }

    size += 10;

    Actor* newArray = new Actor[ size ];

    for( unsigned int i = 0 ; i < noOfActors ; i ++ )
        newArray[i] = actors[i];
    
    newArray[noOfActors] = newActor;

    noOfActors ++;
    delete []  actors;
    actors = newArray;
    return true;

}

//Remove actor list of the film
bool Film::removeActors() 
{
    if( noOfActors == 0 )
        return false;

    noOfActors = 0;
    size = 0;
    delete[] actors;
    actors = new Actor[0];
    return true;

}
