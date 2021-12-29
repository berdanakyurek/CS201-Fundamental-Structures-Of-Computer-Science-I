#ifndef __GENRE_H
#define __GENRE_H
#include <string>
#include "Book.h"
using namespace std;
class Genre {
public:
    Genre(const string gname = "");
    ~Genre();
    Genre (const Genre &genreToCopy);
    void operator=(const Genre &right);
    string getGenreName() const;
    void setGenreName(const string gName);
    bool addBook( const string bName);
    bool removeBook( const string bName );
    void showInfo();

    bool addAuthor( int aID, string aName, string bName );
    bool removeAuthor( int aID, string bName );
    bool displayAuthor(int authorID);
    
private:
    struct BookNode {
        Book b;
        BookNode* next;
    };
    BookNode* head;
    string genreName;
    BookNode* findBook(string bName);
};
#endif