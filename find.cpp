#include "library.hpp"

void    find(vector <CathalogBook> book, string title, string author) {
    auto iter_begin = book.begin(); //объявляем и инициализируем итератор на начало
    auto iter_end = book.end();     //объявляем и инициализируем итератор на конец

    if (iter_begin == iter_end) {   //если вектор пустой
        cout << "Каталог пуст" << endl;
    } else {
        while (iter_begin != iter_end) {    //если не пустой
            if ((*iter_begin).GetTitle() == title && (*iter_begin).ContainsAuthor(author)) {    //если совпадают названия и есть автор в авторах
                cout << "Айди книги по сопадению названия и как минимум одного автора: " << (*iter_begin).GetId() << endl;
                break;
            }
            ++iter_begin;
        }
        if (iter_begin == iter_end) {       //если дошли до конца
            cout << "Книга по названию и автору не найдена" << endl;
        }
    }
}

void    info_by_id(vector <CathalogBook> book, unsigned int id) {
    auto iter_begin = book.begin(); //объявляем и инициализируем итератор на начало
    auto iter_end = book.end();     //объявляем и инициализируем итератор на конец

    if (iter_begin == iter_end) {   //если вектор пустой
        cout << "Каталог пуст" << endl;
    } else {
        while (iter_begin != iter_end) {    //пока не наткнулись на айди - перебор
            if ((*iter_begin).GetId() == id) {  //если совпали айди
                (*iter_begin).ShowInfo();       //выводим инфу
                break;                          //завершаем while
            }
            ++iter_begin;
        }
        if (iter_begin == iter_end) {       //если дошли до конца и ничего не нашлось
            cout << "Книга по айди не найдена" << endl;
        }
    }
}