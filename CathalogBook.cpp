#include "library.hpp"

using namespace std;

CathalogBook::CathalogBook(Book book) {     //кастомный конструктор, чтобы скопировать поля из родительского класса
    this->SetTitle(book.GetTitle());        //сразу в дочерний
    this->SetAuthors(book.GetAuthors());
    this->SetYear(book.GetYear());
    this->SetPublisher(book.GetPublisher());
    this->SetPages(book.GetPages());
}

CathalogBook::CathalogBook() {      //базовый конструктор
}

void CathalogBook::SetId(unsigned int id) {
    this->id = id;
}

unsigned int CathalogBook::GetId() {
    return (this->id);
}

void CathalogBook::SetQuantity(unsigned int quantity) {
    this->quantity = quantity;
}


void CathalogBook::SetInstances(unsigned int instances) {
    this->instances = instances;
}

unsigned int CathalogBook::GetInstances() {
    return (this->instances);
}

void CathalogBook::AddReader(reader person) {
    this->readers.push_back(person);
}

int CathalogBook::ShowReaders() {
    auto iter_begin = readers.begin();
    auto iter_end = readers.end();
    int count = 0;

    if (iter_begin == iter_end) {
        cout << "Список читателей пуст" << endl;
    } else {
        cout << "Читатели: ";
        while (iter_begin != iter_end) {
            cout << count + 1 << ". " << (*iter_begin).name << "\t";
            ++iter_begin;
            ++count;
        }
        cout << endl;
    }
    return (count);
}

void CathalogBook::DeleteReader(unsigned int index) {
    auto iter_begin = readers.cbegin();
    auto iter_end = readers.end();
    if (iter_begin + index < iter_end) {
        readers.erase(iter_begin + index);
        cout << "Читатель удален" << endl;
        this->instances += 1;
    } else {
        cout << "Неверный номер!" << endl;
    }
}

void CathalogBook::TakesBookMoreThanYear() {        //библиотека ctime
    time_t          rawtime;
    struct tm       *timeinfo;

    auto iter_begin = readers.begin();              //итератор начала
    auto iter_end = readers.end();                  //итератор конца

    if (iter_begin != iter_end) {                   //если вектор не пустой
        time(&rawtime);                             //получаем текущее время
        timeinfo = localtime(&rawtime);             //строим структуру по текущему времени
        timeinfo->tm_year = timeinfo->tm_year - 1;  //вычитаем 1 год от тек времени
        rawtime = mktime(timeinfo);                 //получаем число типа time_t, оно же unsigned int
        while (iter_begin != iter_end) {            //идем по вектору читателей
            if (rawtime - (time_t)(*iter_begin).date >= 0)  //приведение типов + если есть время меньше, чем (текущее - 1) год
                cout << this->id << "\t" << (*iter_begin).name << endl; //если нашлось - печатаем id книги и имя читателя
            ++iter_begin;
        }
    }
}

void CathalogBook::ShowInfo() {
    cout << "Айди: " << id << endl;
    cout << "Общее кол-во экземпляров: " << quantity << endl;
    cout << "Кол-во экземпляров в наличии: " << instances << endl;
    this->ShowInfoBook();
    this->ShowReaders();
}