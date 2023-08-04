#ifndef book_h
#define book_h

#include <iostream>
#include <vector>
#include <ctime>
#include "library.hpp"

using namespace std;

class Book {
    private:
        string          title;      //название
        vector<string>  authors;    //автор(ы)
        unsigned int    year;       //год издания
        string          publisher;  //издательство
        unsigned int    pages;      //кол-во страниц
     public:
        void            SetTitle(string title);             //сеттер названия (Set*)
        string          GetTitle();                         //геттер названия (Get*)
        void            AddAuthor(string author);           //добавление автора
        bool            ContainsAuthor(string author);      //проверка, есть ли автор в векторе
        vector<string>  GetAuthors();
        void            SetAuthors(vector<string> authors);
        void            SetYear(unsigned int year);
        unsigned int    GetYear();
        void            SetPublisher(string publisher);
        string          GetPublisher();
        void            SetPages(unsigned int pages);
        unsigned int    GetPages();
        void            ShowAuthors();                      //показать авторов
        void            ShowInfoBook();                     //показать инфо о книге
};

#endif