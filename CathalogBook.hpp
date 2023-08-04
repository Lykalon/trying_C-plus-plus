#ifndef cathalogbook_h
#define cathalogbook_h

#include <iostream>
#include <vector>
#include <ctime>
#include "library.hpp"
#include "Book.hpp"

struct reader {
    string          name;
    unsigned int    date;
};

class CathalogBook : public Book
{
    private:
        unsigned int    id;         //айди в каталоге
        unsigned int    quantity;   //общее кол-во экземпляров
        unsigned int    instances;  //кол-во экз в наличии
        vector<reader>  readers;    //список читателей
    public:
                        CathalogBook(Book book); //конструктор для создания книги в каталоге на основе уже сущ книги
                        CathalogBook(); //базовый конструктор
        void            SetId(unsigned int id); //сеттер для айди
        unsigned int    GetId(); // геттер для айди
        void            SetQuantity(unsigned int quantity); //сеттер
        void            SetInstances(unsigned int instances); //сеттер
        unsigned int    GetInstances(); //геттер
        void            AddReader(reader person); //добавляем читателя
        int             ShowReaders(); //показываем читателей
        void            DeleteReader(unsigned int index); //удаляем читателя по индексу
        void            TakesBookMoreThanYear(); //инфо по должникам
        void            ShowInfo(); //инфо по книге
};

#endif