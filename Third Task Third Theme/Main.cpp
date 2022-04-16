// Third Task Third Theme.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "MyList.h"
#include "User_interface.h"

int main()
{
    setlocale(LC_ALL, "RU");

    MYLIST::my_List static_list;

    menu(static_list);
}

