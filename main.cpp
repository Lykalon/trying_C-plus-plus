#include "library.hpp"

using namespace std;

int main () {
    vector<Book>            base_books;             //вектор книг
    vector<CathalogBook>    cathalog_books;         //вектор каталога
    bool                    exit;                   //флаг завершения
    unsigned int            choice, index;          //для общения с пользователем
    Book                    book;                   //экземпляр книги
    CathalogBook            book_c;                 //экземпляр книги в каталоге
    string                  title, author, reader;  //для общения с пользователем
    long unsigned int       i;                      //для счетчика

    base_books.clear();                             //очищаем вектор
    cathalog_books.clear();                         //очищаем вектор
    setlocale(LC_ALL, "Russian");                   //кодировка
    exit = false;                                   //флаг выхода перед входом в цикл меню
    while (!exit) {
        cout << "1 - добавить книгу" << endl;
        cout << "2 - удалить книгу" << endl;
        cout << "3 - добавить книгу в каталог" << endl;
        cout << "4 - удалить книгу из каталога" << endl;
        cout << "5 - вывести инфо книги из каталога по айди" << endl;
        cout << "6 - найти книгу из каталога по названию и автору" << endl;
        cout << "7 - выдать книгу читателю" << endl;
        cout << "8 - получить книгу от читателя" << endl;
        cout << "9 - список читателей, у кого книги больше года на руках" << endl;
        cout << "10 - выход" << endl;
        cin >> choice;                              //считываем выбор
        switch (choice)
        {
            case 1:
                book = Book();                  //инициализация экземпляра класса
                init_book(&book);               //устанавливаем поля в экземпляре, вызов функции (book_actions.cpp)
                base_books.push_back(book);     //добавляем эклемпляр в вектор
                break;
            
            case 2:
                if (base_books.size() == 0) {                       //если вектор пустой
                    cout << "Список пуст. Удалять нечего!" << endl;
                } else {                                            //если вектор не пустой
                    for (i = 0; i < base_books.size(); ++i) {       //выводим все элементы вектора
                        cout << "Книга № " << i + 1 << endl;        //нумеруем книги
                        base_books[i].ShowInfoBook();               //вызываем метод показать инфо
                    }
                    cout << "Введите номер книги на удаление: ";
                    cin >> choice;                                  //читаем номер книги на удаление
                    auto iterator = base_books.cbegin();            //инициализация итератора начала вектора
                    auto iterator_end = base_books.end();           //инициализация итератора конца вектора
                    if (choice == 0) {                              //костыль, чтобы при 0 не падало в segfault
                        cout << "Некорректный номер" << endl;
                        break;
                    }
                    if (iterator + choice - 1 >= iterator_end)      //если указали номер больше, чем доступно в списке
                        cout << "Некорректный номер" << endl;
                    else {                                          //иначе все ок, переходим к удалению
                        base_books.erase(iterator + choice - 1);    //удаляем
                        cout << "Книга удалена!";
                    }
                }
                break;

            case 3:
                if (base_books.size() == 0) {                           //если вектор пустой
                    cout << "Список книг пуст. Сначала создайте книгу!" << endl;
                } else {                                                //иначе если не пустой
                    for (i = 0; i < base_books.size(); ++i) {           //выводим все элементы вектора
                        cout << "Книга № " << i + 1 << endl;            //нумеруем книги
                        base_books[i].ShowInfoBook();                   //вызываем метод показать инфо
                    }
                    cout << "Введите номер книги для добавления: ";
                    cin >> choice;                                      //читаем номер книги на добавление в каталог
                    auto iterator = base_books.cbegin();                //инициализация итератора начала вектора
                    auto iterator_end = base_books.end();               //инициализация итератора конца вектора
                    if (choice == 0) {                                  //костыль, чтобы при 0 не падало в segfault
                        cout << "Некорректный номер" << endl;
                        break;
                    }
                    if (iterator + choice - 1 >= iterator_end)          //если указали номер больше, чем доступно в списке
                        cout << "Некорректный номер" << endl;
                    else {                                              //иначе все ок, переходим к созданию экземпляра книги в каталоге
                        book_c = CathalogBook(base_books[choice - 1]);  //вызов переопределенного конструктора
                        init_book_cathalog(&book_c);                    //устанавливаем поля в экземпляре (books_library_actions.cpp)
                        cathalog_books.push_back(book_c);               //добавляем эклемпляр в вектор
                    }
                }
                break;

            case 4:
                if (cathalog_books.size() == 0) {                       //если вектор пустой
                    cout << "Каталог пуст. Удалять нечего!" << endl;
                } else {                                                //если вектор не пустой
                    for (i = 0; i < cathalog_books.size(); ++i) {       //выводим все элементы вектора
                        cout << "Книга каталога № " << i + 1 << endl;   //нумеруем книги каталога
                        cathalog_books[i].ShowInfo();                   //вызываем метод показать инфо
                    }
                    cout << "Внимание, вы потеряете всю информацию о действующих читателях!" << endl;
                    cout << "Введите номер книги на удаление: ";
                    cin >> choice;                                      //читаем номер книги в каталоге на удаление
                    if (choice == 0) {                                  //костыль, чтобы при 0 не падало в segfault
                        cout << "Некорректный номер" << endl;
                        break;
                    }
                    auto iterator = cathalog_books.cbegin();
                    auto iterator_end = cathalog_books.end();
                    if (iterator + choice - 1 >= iterator_end)          //если указали номер больше, чем доступно в списке
                        cout << "Некорректный номер" << endl;
                    else {                                              //иначе все ок, переходим к удалению
                        cathalog_books.erase(iterator + choice - 1);    //удаляем
                        cout << "Книга удалена!" << endl;
                    }
                }
                break;

            case 5:
                cout << "Введите номер id: ";
                cin >> choice;                          //читаем айди для поиска
                info_by_id(cathalog_books, choice);     //вызов функции поиска с параметрами (find.cpp)
                break;

            case 6:
                cout << "Введите название книги: ";
                cin >> title;                           //читаем название книги для поиска
                cout << "Введите автора книги: ";
                cin >> author;                          //читаем автора для поиска
                find(cathalog_books, title, author);    //вызов функции с параметрами (find.cpp)
                break;

            case 7:
                if (cathalog_books.size() == 0) {                               //если вектор пустой
                    cout << "В каталоге нет книг!" << endl;
                } else {                                                        //если вектор не пустой
                    for (i = 0; i < cathalog_books.size(); ++i) {               //для каждой книги в векторе
                        cout << "Книга каталога № " << i + 1 << endl;           //нумеруем книги каталога
                        cathalog_books[i].ShowInfo();                           //вызываем метод ShowInfo
                    }
                    cout << "Введите номер книги для выдачи: ";
                    cin >> choice;                                              //читаем номер книги в каталоге
                    if (choice == 0) {                                          //костыль, чтобы при 0 не падало в segfault
                        cout << "Некорректный номер" << endl;
                        break;
                    }
                    auto iterator = cathalog_books.cbegin();                    //инициализация итератора начала вектора
                    auto iterator_end = cathalog_books.end();                   //инициализация итератора конца вектора
                    if (iterator + choice - 1 >= iterator_end)                  //если указали номер больше, чем доступно в списке                  
                        cout << "Некорректный номер" << endl;
                    else {                                                      //если все ок, идем дальше
                        if (cathalog_books[choice - 1].GetInstances() < 1) {    //проверяем, что есть доступные для выдачи книги
                            cout << "Нет доступных книг для выдачи!" << endl;
                        } else {
                            cout << "Введите имя читателя: ";
                            cin >> reader;                                      //если все ок, то считываем имя читателя
                            give_book(reader, &cathalog_books[choice - 1]);     //вызываем функцию с параметрами (readers.cpp)
                        }
                    }
                }
                break;

            case 8:
                if (cathalog_books.size() == 0) {                               //если вектор пустой
                    cout << "В каталоге нет книг!" << endl;
                } else {                                                        //если вектор не пустой
                    for (i = 0; i < cathalog_books.size(); ++i) {               //для каждой книги в векторе
                        cout << "Книга каталога № " << i + 1 << endl;           //нумеруем книги каталога
                        cathalog_books[i].ShowInfo();                           //вызываем метод ShowInfo
                    }
                    cout << "Введите номер книги для возврата: ";
                    cin >> choice;
                    if (choice == 0) {                                          //костыль, чтобы при 0 не падало в segfault
                        cout << "Некорректный номер" << endl;
                        break;
                    }
                    auto iterator = cathalog_books.cbegin();                    //инициализация итератора начала вектора
                    auto iterator_end = cathalog_books.end();                   //инициализация итератора конца вектора
                    if (iterator + choice - 1 >= iterator_end)                  //если указали номер больше, чем доступно в списке
                        cout << "Некорректный номер" << endl;
                    else {
                        if (cathalog_books[choice - 1].ShowReaders() > 0) {     //фича - метод ShowReader возвращает кол-во читателей, 
                            cout << "Введите номер читателя, который возвращает книгу: "; //а в теле метода печатает читателей, если есть
                            cin >> index;                                       //поэтому мы сразу делаем выбор, удалять или нет, в зависимости
                            cathalog_books[choice - 1].DeleteReader(index - 1); //от кол-ва отображенных читателей :)
                        } else {
                            cout << "По данной книге нет читателей" << endl;
                        }
                    }
                }
                break;

            case 9:
                for (i = 0; i < cathalog_books.size(); ++i)     //для каждого элемента в векторе каталога
                    cathalog_books[i].TakesBookMoreThanYear();  //вызов метода класса
                break;

            case 10:
                exit = true;    //выход из цикла
                break;

            default: break;
        };

    };
    return (0);
}