#include "library.hpp"

using namespace std;

void Book::SetTitle(string title) {
    this->title = title;
}

string Book::GetTitle() {
    return (title);
}

void Book::AddAuthor(string author) {
    this->authors.push_back(author);
}

bool Book::ContainsAuthor(string author) {  //проверка на автора в векторе
    auto iter_begin = authors.begin();
    auto iter_end = authors.end();

    while (iter_begin != iter_end) {
        if (author == *iter_begin)          //*iter_begin - разыменование. Получаем значение которое по адресу лежит
            return (true);
        ++iter_begin;
    }
    return (false);
}

void Book::SetAuthors(vector<string> authors) {
    this->authors = authors;
}

vector<string> Book::GetAuthors() {
    return (this->authors);
}

void Book::SetYear(unsigned int year) {
    this->year = year;
}

unsigned int Book::GetYear() {
    return (this->year);
}

void Book::SetPublisher(string publisher) {
    this->publisher = publisher;
}

string Book::GetPublisher() {
    return (this->publisher);
}

void Book::SetPages(unsigned int pages) {
    this->pages = pages;
}

unsigned int Book::GetPages() {
    return (this->pages);
}

void Book::ShowAuthors() {                  //показываем авторов
    auto iter_begin = authors.begin();
    auto iter_end = authors.end();

    cout << "Автор(ы): ";
    while (iter_begin != iter_end) {
        cout << "\t" << *iter_begin;        //*iter_begin - разыменование. Получаем значение которое по адресу лежит
        ++iter_begin;
    }
    cout << endl;
}

void Book::ShowInfoBook() {
    cout << "Название: " << title << endl;
    this->ShowAuthors();
    cout << "Год издания: " << year << endl;
    cout << "Издательство: " << publisher << endl;
    cout << "Кол-во страниц: " << pages << endl;
}