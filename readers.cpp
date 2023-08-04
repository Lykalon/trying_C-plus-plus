#include "library.hpp"

void    give_book(string name, CathalogBook *book) {
    time_t          rawtime;
    struct tm       *timeinfo;
    int             year, month, day;
    reader          human;

    cout << "Введите год выдачи книги: ";
    cin >> year;
    cout << "Введите месяц выдачи книги: ";
    cin >> month;
    cout <<  "Введите день выдачи книги: ";
    cin >> day;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    rawtime = mktime(timeinfo);
    human.name = name;
    human.date = (unsigned int)rawtime;
    book->AddReader(human);
}