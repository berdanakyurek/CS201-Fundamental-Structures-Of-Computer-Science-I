// Berdan Akyurek
//21600904
//CS201 HW1

#include "SimpleFC.h"
#include <string>
using namespace std;
#include <iostream>

// constructor for FC object
FC::FC()
{
    films = new Film[0];
    noOfFilms = 0;
    size = 0;
    
    
}

// copy constructor for FC object
FC::FC(const FC &fcToCopy)
{
    noOfFilms = fcToCopy.noOfFilms;
    size = fcToCopy.size;

    films = new Film[size];

    for( int i = 0 ; i < noOfFilms ; i ++ )
        films[i] = fcToCopy.films[i];


}

// destructor for FC object
FC::~FC()
{
    delete[] films;
}

// = operator overloading
void FC::operator=(const FC &right)
{
    noOfFilms = right.noOfFilms;
    size = right.size;

    delete[] films;

    films = new Film[size];

    for( int i = 0 ; i < noOfFilms ; i ++ )
        films[i] = right.films[i];

}

// add film
bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration)
{
    
    
    for( int i = 0; i < noOfFilms; i ++ ) //check if the film already exist or not 
    {
        if ( films[i].getTitle() == fTitle && films[i].getDirector() == fDirector )
            return false;
    }

    Film f(fTitle, fDirector, fYear, fDuration ); //create new film to add

    if( size > noOfFilms )
    {
        films[noOfFilms] = f;
        noOfFilms ++;
        return true;
    }

    noOfFilms ++;
    size += 10;
    Film* newArray = new Film[size]; //create new array

    for( int i = 0; i < noOfFilms - 1; i ++) //add old films to new array
        newArray[i] = films[i];

    newArray[noOfFilms - 1] = f; //add new film to new array

    delete[] films;

    films = newArray;


    return true;

    

}

// remove film 
bool FC::removeFilm(const string fTitle, const string fDirector)
{
    int index = -1;

    // find the index of film
    for( int i = 0 ; i < noOfFilms ; i ++ )
    {
        if( films[i].getTitle() == fTitle && films[i].getDirector() == fDirector )
        {
            index = i;
            break;
        }
    }

    if( index == -1 )
        return false;


    noOfFilms --;

    Film* newArray = new Film[size];
    int j = 0;
    for( int i = 0 ; i < noOfFilms + 1 ; i ++ )
    {
        if( index != i )
            newArray[j] = films[i];
        else
            j--;

        j ++;
    }

    delete[] films;
    films = newArray;
    return true;
}

//get films
unsigned int FC::getFilms(Film *&allFilms) const
{
    allFilms = new Film[noOfFilms];
    for( int i = 0 ; i < noOfFilms ; i ++ )
        allFilms[i] = films[i];
    return noOfFilms;
}