#include "library.hpp"

using namespace std;

void    init_book(Book *book) {     //  ----------------->  на вход идет указатель на экземпляр, чтобы
    string          title;          //название              мы поменяли поля в самом экземпляре
    string          author;         //автор                 а не в его копии при вызове функции
    unsigned int    author_count;   //кол-во авторов
    unsigned int    year;           //год издания
    string          publisher;      //издательство
    unsigned int    pages;          //кол-во страниц
    unsigned int    i;

    cout << "Введите название книги: " << endl;
    cin >> title;
    book->SetTitle(title);                          //вызов сеттера
    cout << "Введите кол-во авторов: " << endl;
    cin >> author_count;                            //если ввели 0, будет заглушка Default
    if (author_count < 1) {
        cout << "Введено не верное кол-во! Автор установлен по умолчанию" << endl;
        book->AddAuthor("Default");
    } else {                                        //если ввели норм число, в цикле заполняем
        for (i = 0; i < author_count; i++) {
            cout << "Введите автора " << i + 1 << endl;
            cin >> author;
            book->AddAuthor(author);                //вызов метода добавления автора
        }
    }
    cout << "Введите год издания: " << endl;
    cin >> year;
    book->SetYear(year);                            //сеттер года
    cout << "Введите издательство: " << endl;
    cin >> publisher;
    book->SetPublisher(publisher);                  //сеттер издательства
    cout << "Введите кол-во страниц:" << endl;
    cin >> pages;                                   //сеттер страниц
    book->SetPages(pages);
}