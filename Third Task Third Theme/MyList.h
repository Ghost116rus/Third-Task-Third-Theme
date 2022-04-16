#pragma once
#include <iostream>
#include <functional>
#include "Queue.h"

enum MyEnum
{
	Not_found = -1,
	Find_el,
};


namespace MYLIST
{
	/* Узловой элемент списка */
	struct Node
	{
		int data = 0;
		int next_ptr = NULL;
	};

	/* Сама структура */
	struct my_List
	{
		int count = 1;					// Количество элементов в массиве
		Node fix_arr[Array_Size+1];		// Сам массив
		Queue::queue free_array_cells;  // Очередь свободных ячеек массива
	};

	/* Функция инициализации */
	void init(my_List& ml);

	/// <summary>
	/// Функция вывода списка на экра
	/// </summary>
	/// <param name="m_l">Получает ссылку на список</param>
	void show(my_List& m_l);

	/// <summary>
	/// Функция проверки списка на заполненность  
	/// </summary>
	/// <param name="m_l">Получает ссылку на список</param>
	/// <returns>Возвращает булевую переменую - полон ли список</returns>
	bool full(my_List& m_l);

	/// <summary>
	/// Функция проверки списка на пустоту  
	/// </summary>
	/// <param name="m_l">Получает ссылку на список</param>
	/// <returns>Возвращает булевую переменую - пуст ли список</returns>
	bool empty(my_List& m_l);


	/// <summary>
	/// Функция поиска заданного элемента
	/// </summary>
	/// <param name="m_l">Получает ссылку на список</param>
	/// <param name="find_data">Получает элемент, который надо найти</param>
	/// <returns>Возвращает индекс найденного элемента</returns>
	int find_v2(my_List& m_l, int find_data);

	/// <summary>
	/// Функция добавления нового элемента
	/// </summary>
	/// <param name="m_l">Получает ссылку на список</param>
	/// <param name="data">Вставляемые данные</param>
	/// <param name="find_data">Ищет расположение элемента с такими данными</param>
	/// <param name="after">Отвечает за расположение нового элемента до/после заданного</param>
	void add(my_List& m_l, int data, int find_data, bool after);

	/// <summary>
	/// Функция удаления элемента
	/// </summary>
	/// <param name="m_l"></param>
	/// <param name="data">Получает данные, которые нужно удалить</param>
	void remove(my_List& m_l, int find_data);
}
