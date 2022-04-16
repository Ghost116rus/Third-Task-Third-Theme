#pragma once
#include <iostream>

const int Array_Size = 8;

namespace Queue
{
	struct queue
	{
		int fixed_array[Array_Size-1]{};
		int* first_ptr;
		int* last_ptr;

		int* start_of_arr;
		int count;
	};

	/* функция инициализации очереди */
	void init(queue& q_ref);

	/* функция проверки на пустоту очереди */
	bool empty(queue& q_ref);

	/* функция проверки заполненности */
	bool full(queue& q_ref);

	/* добавление элемента в конец очереди */
	void add(queue& q_ref, int data);

	/* удаление первого элемента */
	int pop(queue& q_ref);

	/* функция вывода очереди на экран*/
	void show(queue& q_ref);
}