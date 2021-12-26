// Berdan Akyurek
// 21600904

#include "BookCollection.h"
#include <iostream>

BookCollection::BookCollection()
{
    genreCount = 0;
    head = NULL;
}

BookCollection::~BookCollection()
{
    GenreNode* current = head;

    for( int i = 0 ; i < genreCount ; i ++ )
    {
        current = current->next;
        delete head;
        head = current;
    }
}

BookCollection::BookCollection(const BookCollection& bcToCopy)
{
    GenreNode* current = head;
    GenreNode* current2 = bcToCopy.head;

    int genreCount2 = bcToCopy.genreCount;
    if( genreCount2 != 0 )
        current = new GenreNode;
    head = current;

    for( int i = 1 ; i < genreCount2 ; i ++ )
    {
        current->g = current2->g;
        if( current2 ->next != NULL )
            current ->next = new GenreNode;
        else
        {
            current ->next = NULL;
            break;
        }
        
        current2 = current2 ->next;
        current = current ->next;
    }
    genreCount = bcToCopy.genreCount;

}

void BookCollection::operator=(const BookCollection& right)
{
    GenreNode* current = head;

    for( int i = 0 ; i < genreCount ; i ++ )
    {
        current = current->next;
        delete head;
        head = current;
    }

    genreCount = 0;
    GenreNode* current2 = right.head;
    current = head;

    int genreCount2 = right.genreCount;
    if( genreCount2 != 0 )
        current = new GenreNode;
    head = current;

    for( int i = 1 ; i < genreCount2 ; i ++ )
    {
        current->g = current2->g;
        if( current2 ->next != NULL )
            current ->next = new GenreNode;
        else
        {
            current ->next = NULL;
            break;
        }
        
        current2 = current2 ->next;
        current = current ->next;
    }
    genreCount = right.genreCount;
}

void BookCollection::addGenre(string genreName)
{
    GenreNode* current = head;

    if( genreCount == 0 )
    {
        head = new GenreNode;
        Genre gToAdd(genreName);
        head ->g = gToAdd;
        head ->next = NULL;
        genreCount ++;
        return;
    }
    for( int i = 0 ; i < genreCount ; i ++ )
    {
        if( (current -> g).getGenreName() == genreName )
        {
            cout << "This genre already exists! " << endl;
            return;
        }

        if( current -> next == NULL )
        {
            Genre gToAdd(genreName);
            current ->next = new GenreNode;
            current ->next ->g = gToAdd;
            current ->next ->next = NULL;
            genreCount ++;
            return;
        }
        current = current ->next;
    }
}

void BookCollection::removeGenre (string genreName)
{
    GenreNode* genreToRemove = findGenre( genreName );

    if( genreToRemove == NULL )
    {
        cout << "There is not a genre named " << genreName << "!" << endl;
        return;
    }

    if( genreToRemove == head )
    {
        head = genreToRemove -> next;
        delete genreToRemove;
        genreCount --;
        return;
    }

    GenreNode* current = head;
    GenreNode* second = head ->next;

    for( int i = 0; i < genreCount ; i ++ )
    {
        if( second == genreToRemove )
        {
            current ->next = second ->next;
            delete genreToRemove;
            genreCount --;
            return;
        }
        current = current->next;
        second = second->next;
    }

}

void BookCollection::displayAllGenres() const
{
    if( genreCount == 0 )
    {
        cout << "--EMPTY--" <<endl;
        return;
    }

    GenreNode* current = head;
    for( int i = 0 ; i < genreCount ; i ++ )
    {
        cout << (current->g).getGenreName() << endl;
        current = current->next;
    }
}

void BookCollection::addBook(string genreName, string bookName)
{
    GenreNode* gToAddB = findGenre( genreName );

    if( gToAddB == NULL )
    {
        cout << "There is not a genre named " << genreName << "!" << endl;
        return;
    }

    (gToAddB->g).addBook( bookName );

}

void BookCollection::removeBook(string genreName, string bookName)
{
    GenreNode* gToRemoveB = findGenre( genreName );

    if( gToRemoveB == NULL )
    {
        cout << "There is not a genre named " << genreName << "!" << endl;
        return;
    }

    (gToRemoveB->g).removeBook( bookName );

}

void BookCollection::addAuthor(string genreName, string bookName, int authorID, string authorName)
{
    GenreNode* gToAddA = findGenre( genreName );

    if( gToAddA == NULL )
    {
        cout << "There is not a genre named " << genreName << "!" << endl;
        return;
    }

    (gToAddA->g).addAuthor( authorID, authorName, bookName );
}

void BookCollection::removeAuthor(string genreName, string bookName, int authorID)
{
    GenreNode* gToRemove = findGenre( genreName );

    if( gToRemove == NULL )
    {
        cout << "There is not a genre named " << genreName << "!" << endl;
        return;
    }

    (gToRemove->g).removeAuthor( authorID, bookName );
}

void BookCollection::displayGenre(string genreName)
{
    GenreNode* gToDisplay = findGenre( genreName );

    if( gToDisplay == NULL )
    {
        cout << "There is not a genre named " << genreName << "!" << endl;
        return;
    }

    (gToDisplay->g).showInfo();
}

void BookCollection::displayAuthor(int authorID)
{
    cout << authorID << endl;
    GenreNode* current = head;
    bool printed = false;
    for( int i  = 0 ; i < genreCount ; i ++ )
    {
        if( current->g.displayAuthor( authorID ) == true)
            printed = true;

        current = current -> next;
    }
    if ( printed == false )
        cout << "--EMPTY--" << endl;    
}

BookCollection::GenreNode* BookCollection::findGenre(string genreName)
{
    if( head == NULL )
        return NULL; 
    
    GenreNode* current = head;

    for( int i = 0 ; i < genreCount ; i ++ )
    {
        if( (current->g).getGenreName() == genreName )
            return current;
        current = current->next;
    }
    return NULL;
}