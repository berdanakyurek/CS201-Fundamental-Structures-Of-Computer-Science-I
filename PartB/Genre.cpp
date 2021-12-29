// Berdan Akyurek
// 21600904

#include "Genre.h"
#include <iostream>
Genre::Genre(const string gname)
{
    genreName = gname;
    head = NULL;
}

Genre::~Genre ()
{
    BookNode* current = head;

    while( current != NULL )
    {
        current = current ->next;
        delete head;
        head = current;
    }
}

Genre::Genre(const Genre &genreToCopy)
{
    BookNode* current = head;
    BookNode* current2 = genreToCopy.head;
    if( current2 != NULL )
        current = new BookNode;
    head = current;
    while( current2 != NULL )
    {
        current->b = current2->b;
        if( current2 ->next != NULL )
            current ->next = new BookNode;
        else
        {
            current ->next = NULL;
            break;
        }
        
        current2 = current2 ->next;
        current = current ->next;
    }
}

void Genre::operator=(const Genre &right)
{
    genreName = right.genreName;

    BookNode* current = head;

    while( current != NULL )
    {
        current = current ->next;
        delete head;
        head = current;
    }

    current = head;
    BookNode* current2 = right.head;
    if( current2 != NULL )
        current = new BookNode;
    head = current;
    while( current2 != NULL )
    {
        current->b = current2->b;
        if( current2 ->next != NULL )
            current ->next = new BookNode;
        else
        {
            current ->next = NULL;
            break;
        }
        
        current2 = current2 ->next;
        current = current ->next;
    }
}

string Genre::getGenreName() const
{
    return genreName;
}

void Genre::setGenreName(const string gName)
{
    genreName = gName;
}

bool Genre::addBook( const string bName)
{
    BookNode* current = head;
    
    if( current == NULL )
    {
        head = new BookNode;
        head->b.setName(bName);
        head->next = NULL;
        return true;
    }

    while( current != NULL )
    {
        if( (current->b).getName() == bName )
        {
            cout << "This book already exist in this Genre!" << endl;
            return false;
        }

        if( current->next == NULL )
        {
            current->next = new BookNode;
            (current->next->b).setName( bName );
            (current->next->next) = NULL;
            current = current -> next;
            return true;
        }
        current = current -> next;
    }

    return false;
}

bool Genre::removeBook( const string bName )
{
    BookNode* toRemove = findBook( bName );

    if(  toRemove == NULL )
    {
        cout << "There is not a book named " << bName << " in this Genre!" << endl;
        return false;
    }
    BookNode* current;

    if( head == toRemove )
    {
        current = head->next;
        delete head;
        head = current;
        return true;
    }

    current = head;
    BookNode* second = current->next;

    while( second != NULL )
    {
        if( second == toRemove )
        {
            current ->next = second ->next;
            delete second;
            return true;
        }
        current = current->next;
        second = second->next;
    }

    return false;
}

void Genre::showInfo()
{
    cout << genreName << endl;

    if( head == NULL )
        cout << "--EMPTY--" << endl;
        
    else
    {
        BookNode* current = head;

        while (current != NULL)
        {
            cout << current->b.getName() << endl;
            current->b.displayAuthors();
            current = current->next;
        } 
    }
    
}

Genre::BookNode* Genre::findBook(string bName)
{
    if( head == NULL )
        return NULL;
    
    BookNode* current = head;

    while( current != NULL )
    {
        if( current->b.getName() == bName )
            return current;
        current = current->next;
    }

    return NULL;
}



//Following functions are calling the functions of Book class

bool Genre::addAuthor( int aID, string aName, string bName )
{
    BookNode* bookToAddA = findBook( bName );
    
    if( bookToAddA == NULL )
    {
        cout << "There is not a book named " << bName << " in this Genre!" << endl;
        return false;
    }

    return (bookToAddA->b).addAuthor( aID, aName );
    
}

bool Genre::removeAuthor( int aID, string bName )
{
    BookNode* bookToRemA = findBook( bName );
    
    if( bookToRemA == NULL )
    {
        cout << "There is not a book named " << bName << " in this Genre!" << endl;
        return false;
    }

    return (bookToRemA->b).removeAuthor( aID );
}

bool Genre::displayAuthor(int authorID)
{
    bool printed = false;
    BookNode* current = head;
    cout << genreName << endl;
    if( current == NULL )
        return false;
    while( current != NULL )
    {
        if ( current->b.printBookIfHasAuthor( authorID ) == true )
        {
            printed = true;
        }
        
        current = current->next;
    }

    if( printed == false )
        cout << "   --EMPTY--" << endl;
    return printed; 
}