#include "library.hpp"

using namespace std;

void    init_book_cathalog(CathalogBook *book) { //установка полей в экземпляре класса
    unsigned int    id;         //айди в каталоге
    unsigned int    quantity;   //общее кол-во экземпляров
    unsigned int    instances;  //кол-во экз в наличии

    cout << "Введите айди книги: " << endl;
    cin >> id;
    book->SetId(id);
    cout << "Введите общее кол-во экземпляров: " << endl;
    cin >> quantity;
    book->SetQuantity(quantity);
    cout << "Введите кол-во экземпляров в наличии: " << endl;
    cin >> instances;
    while (instances > quantity) {            //проверка на кол-во доступно и всего
        cout << "В наличии не может быть больше чем общее кол-во!" << endl;
        cout << "Введите кол-во экземпляров в наличии: " << endl;
        cin >> instances;
    }
    book->SetInstances(instances);
}