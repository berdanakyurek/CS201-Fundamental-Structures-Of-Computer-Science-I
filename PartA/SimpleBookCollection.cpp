// Berdan Akyurek
//21600904

#include "SimpleBookCollection.h"
#include <iostream>
#include <algorithm>

BookCollection::BookCollection()
{
    genreCount = 0;
    name = "";
    head = NULL;
}

BookCollection::~BookCollection()
{
    if ( genreCount == 1 )
        delete head;

    GenreNode* curr;
    GenreNode* nex;
    curr = head;

    if( genreCount > 1 )
    {
        for( int i = 0 ; i < genreCount ; i ++ )
        {
            nex = curr->next;
            delete curr;
            curr = nex;
        }   
    }
}
BookCollection::BookCollection(const BookCollection& bcToCopy)
{
    name = bcToCopy.name;
    genreCount = 0;

    GenreNode* current = bcToCopy.head;
    for( int i = 0; i < bcToCopy.genreCount ; i ++ )
    {
        addGenre((current->g).getGenreName());
        current = current -> next;
    }
}

void BookCollection::operator=(const BookCollection& right)
{
    name = right.name;
    
    if ( genreCount == 1 )
        delete head;

    GenreNode* curr;
    GenreNode* nex;
    curr = head;

    if( genreCount > 1 )
    {
        for( int i = 0 ; i < genreCount ; i ++ )
        {
            nex = curr->next;
            delete curr;
            curr = nex;
        }   
    }

    genreCount = 0;
    GenreNode* current;
    current = right.head;

    for( int i = 0 ; i < right.genreCount ; i ++ )
    {
        addGenre((current -> g).getGenreName());
        current = current -> next;
    }
}

void BookCollection::displayGenres() const
{
    GenreNode* current;
    current = head;
    if( genreCount == 0 )
        cout << "--EMPTY--" << endl;
    
    for ( int i = 0 ; i < genreCount ; i ++ )
    {
        cout << (current -> g).getGenreName() << endl;
        current = current -> next;

    }
}

bool BookCollection::addGenre(const string genreName)
{
    string genreNametolower = genreName;

    for_each(genreNametolower.begin(), genreNametolower.end(), [](char & c) {
		c = ::tolower(c);
	});

    GenreNode* newNode = new GenreNode; 
    (newNode -> g).setGenreName(genreName);
    newNode -> next = NULL;


    if( genreCount == 0 )
    {
        head = newNode;
        genreCount ++;
        return true;
    }

    GenreNode* current;
    current = head;
    string currentNametoLower;
    for( int i = 0 ; i < genreCount ; i ++ )
    {
        currentNametoLower = (current -> g ).getGenreName();
        
        for_each(currentNametoLower.begin(), currentNametoLower.end(), [](char & c) {
		    c = ::tolower(c);
	    });

        if( currentNametoLower == genreNametolower )
        {
            delete newNode;
            cout << "This book already exist in this collection!" << endl;
            return false;
        }

        if( current -> next == NULL )
        {
            current -> next = newNode;
            genreCount ++;
            return true;
        }
        current = current -> next;
    }
    return true;
}

bool BookCollection::removeGenre(const string genreName)
{
    GenreNode* asd = findGenre(genreName);

    if( asd == NULL )
        return false;

    GenreNode* current;
    current = head;

    if( asd == head )
    {
        head = current -> next;
        delete current;
        genreCount --;
        return true;
    }

    for(  int i = 0 ; i < genreCount ; i ++ )
    {
        if( current -> next == asd )
        {
            current -> next = asd -> next;
            delete asd;
            genreCount --;
            return true;
        }
        current = current -> next;
    } 
    return true;
}

string BookCollection::getName() const
{
    return name;
}

void BookCollection::setName(const string bcName)
{
    name = bcName;
}

BookCollection::GenreNode* BookCollection::findGenre(string genreName)
{

    string genreNametolower = genreName;

    for_each(genreNametolower.begin(), genreNametolower.end(), [](char & c) {
		c = ::tolower(c);
	});
    
    GenreNode* current;
    current = head;
    string currentNametoLower;

    for( int i = 0 ; i < genreCount ; i ++)
    {
        currentNametoLower = (current -> g ).getGenreName();
        
        for_each(currentNametoLower.begin(), currentNametoLower.end(), [](char & c) {
		    c = ::tolower(c);
	    });

        if( currentNametoLower == genreNametolower )
        {
            return current;
        }
        current = current -> next;
    }

    return NULL;
}
