// Berdan Akyurek
// 21600904

#include "Book.h"
#include <iostream>

Book::Book()
{
    name = "";
    head = NULL;
    noOfAuthors = 0;
}

Book::Book( const string nameA )
{
    name = nameA;
    head = NULL;
    noOfAuthors = 0;
}

Book::~Book()
{
    if ( noOfAuthors == 1 )
        delete head;

    AuthorNode* curr;
    AuthorNode* nex;
    curr = head;

    if( noOfAuthors > 1 )
    {
        for( int i = 0 ; i < noOfAuthors ; i ++ )
        {
            nex = curr->next;
            delete curr;
            curr = nex;
        }   
    }
}

Book::Book(const Book& bookToCopy)
{
    name = bookToCopy.name;
    noOfAuthors = 0;

    head = NULL;

    AuthorNode* current = bookToCopy.head;

    for( int i = 0; i < bookToCopy.noOfAuthors ; i ++ )
    {
        addAuthor((current->a).getID(),(current->a).getName());
        current = current -> next;
    }
}

void Book::operator= (const Book& right)
{
    name = right.name;
    
    if ( noOfAuthors == 1 )
        delete head;

    AuthorNode* curr;
    AuthorNode* nex;
    curr = head;

    if( noOfAuthors > 1 )
    {
        for( int i = 0 ; i < noOfAuthors ; i ++ )
        {
            nex = curr->next;
            delete curr;
            curr = nex;
        }   
    }

    noOfAuthors = 0;
    AuthorNode* current;
    current = right.head;

    for( int i = 0 ; i < right.noOfAuthors ; i ++ )
    {
        addAuthor((current -> a).getID(), (current -> a).getName());
        current = current -> next;
    }
}

string Book::getName() const
{
    return name;
}

void Book::setName(const string bookName)
{
    name = bookName;
}

bool Book::addAuthor(const int id, const string name)
{
    

    AuthorNode* newNode = new AuthorNode; 
    (newNode -> a).setID(id);
    (newNode -> a).setName(name);
    newNode -> next = NULL;


    if( noOfAuthors == 0 )
    {
        head = newNode;
        noOfAuthors ++;
        return true;
    }

    AuthorNode* current;
    current = head;
    for( int i = 0 ; i < noOfAuthors ; i ++ )
    {

        if( id == (current -> a).getID() )
        {
            delete newNode;
            cout << "This Author already exist in this Book!" << endl;
            return false;
        }

        if( current -> next == NULL )
        {
            current -> next = newNode;
            noOfAuthors ++;
            return true;
        }
        current = current -> next;
    }
    return true;
}

bool Book::removeAuthor (const int id)
{
    AuthorNode* asd = findAuthor(id);

    if( asd == NULL )
        return false;

    AuthorNode* current;
    current = head;

    if( asd == head )
    {
        head = current -> next;
        delete current;
        noOfAuthors --;
        return true;
    }

    for(  int i = 0 ; i < noOfAuthors ; i ++ )
    {
        if( current -> next == asd )
        {
            current -> next = asd -> next;
            delete asd;
            noOfAuthors --;
            return true;
        }
        current = current -> next;
    } 
    return true;
}

void Book::displayAuthors() const
{
    AuthorNode* current;
    current = head;
    if( noOfAuthors == 0 )
        cout << "   --EMPTY--" << endl;
    
    for ( int i = 0 ; i < noOfAuthors ; i ++ )
    {
        cout << "   " << (current -> a).getID() << ", " << (current -> a).getName() << endl;
        current = current -> next;

    }
}

Book::AuthorNode* Book::findAuthor(int id)
{
    
    AuthorNode* current;
    current = head;

    for( int i = 0 ; i < noOfAuthors ; i ++)
    {

        if( id == (current->a).getID() )
        {
            return current;
        }
        current = current -> next;
    }
    return NULL;
}

bool Book::printBookIfHasAuthor( int id )
{
    AuthorNode* current = head;
   for( int i = 0 ; i < noOfAuthors ; i ++ )
   {
        if( current->a.getID() == id )
        {
            cout << "   " << name << endl;
            return true;
        }
        current = current -> next;
   }
   return false;
}