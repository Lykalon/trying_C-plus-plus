#ifndef library_h
#define library_h

#include <iostream>
#include <vector>
#include <ctime>
#include "CathalogBook.hpp"
#include "Book.hpp"

using namespace std;

void    init_book(Book *book);
void    init_book_cathalog(CathalogBook *book);
void    info_by_id(vector <CathalogBook> book, unsigned int id);
void    find(vector <CathalogBook> book, string title, string author);
void    give_book(string name, CathalogBook *book);

#endif