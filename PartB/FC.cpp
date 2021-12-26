#include <iostream>
#include <string>

#include "FC.h"

// Constructor
FC::FC()
{
    size = 0;
    noOfFilms = 0;
     films = new Film[0];
}

// Copy Constructor 
FC::FC(const FC &fcToCopy)
{
    size = fcToCopy.size;
    noOfFilms = fcToCopy.noOfFilms;
    films = new Film[size];

    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
        films[i] = fcToCopy.films[i];
}

// Destructor
FC::~FC()
{
    delete[] films;
}

// Assignment operator 
void FC::operator=(const FC &right)
{
    size = right.size;
    noOfFilms = right.noOfFilms;
    delete[] films;
    films = new Film[size];

    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
        films[i] = right.films[i];
}

// Add a film to FC
bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration)
{
    // check if it already exists
    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
    {
        if( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
            return false;
    }
    // create the film
    Film f( fTitle, fDirector, fYear, fDuration );

    // Add film 

    if( size > noOfFilms )
    {
        films[noOfFilms] = f;
        noOfFilms ++;
        return true;
    }

    size += 10;

    Film* newArray = new Film[size];

    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
        newArray[i] = films[i];
    
    newArray[noOfFilms] = f;
    noOfFilms ++;
    delete[] films;
    films = newArray;
    return true;

}

// Remove a film from FC
bool FC::removeFilm(const string fTitle, const string fDirector)
{
    int index = -1;
    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
    {
        if( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
        {
            index = i;
            break;
        }
    }

    if( index == -1 )
        return false;

    // delete index'th element of array
    Film* newArray = new Film[size];

    unsigned int j = 0;
    for( int i = 0 ; i < noOfFilms ; i ++ )
    {
        if( i == index )
            continue;
        
        newArray[j] = films[i];
        j ++;
    }

    delete[] films;
    films = newArray;
    
    noOfFilms --;
    return true;
}

// Get function
unsigned int FC::getFilms(Film *&allFilms) const
{
    allFilms = new Film[noOfFilms];

    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
        allFilms[i] = films[i];
    return noOfFilms;
}

// Add an actor to a film
bool FC::addActor(const string fTitle, const string fDirector, const string aName, const string aBirthPlace, const unsigned int aBirthYear)
{
    int index = -1;
    
    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
    {
        if( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
        {
            index = i;
            break;
        }
    }
    if( index == -1 )
        return false;
        
    return films[index].addActor( aName, aBirthPlace, aBirthYear );
}

// Remove actors list of a film
bool FC::removeActors(const string fTitle, const string fDirector)
{
    int index = -1;

    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
    {
        if( films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector )
        {
            index = i;
            break;
        }
    }

    if  ( index == -1 )
        return false;

    return films[index].removeActors();
}

// Calculate average duration
unsigned int FC::calculateAverageDuration() const
{
    if( noOfFilms == 0 )
        return 0;
    
    unsigned int sum = 0;

    for( unsigned int i = 0 ; i < noOfFilms ; i ++ )
        sum += films[i].getFilmDuration();

    return sum / noOfFilms;
}