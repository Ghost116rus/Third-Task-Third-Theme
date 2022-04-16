// Third Task Third Theme.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "MyList.h"

int main()
{
    setlocale(LC_ALL, "RU");

    MYLIST::my_List static_list;

    MYLIST::init(static_list);
    std::cout << "\n"; Queue::show(static_list.free_array_cells); std::cout << "\n";

    MYLIST::add(static_list, 16, 55, false);
    MYLIST::add(static_list, 8, 16, false);
    MYLIST::add(static_list, 2, 16, true);

    MYLIST::show(static_list);
    std::cout << "\n"; Queue::show(static_list.free_array_cells); std::cout << "\n";


    MYLIST::remove(static_list, 16);
    MYLIST::show(static_list);
    MYLIST::add(static_list, 15, 2, true);
    MYLIST::add(static_list, 56, 2, false);
    MYLIST::remove(static_list, 56);

    MYLIST::show(static_list);
    std::cout << "\n"; Queue::show(static_list.free_array_cells); std::cout << "\n";

}

