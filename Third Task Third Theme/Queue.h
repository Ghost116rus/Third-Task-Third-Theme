#pragma once
#include <iostream>
#include "Node.h"



namespace Queue
{
	struct queue
	{
		Node* fixed_array[Array_Size-1]{};
		Node** first_ptr;
		Node** last_ptr;

		Node** start_of_arr;
		int count;
	};

	/* функция инициализации очереди */
	void init(queue& q_ref);

	/* функция проверки на пустоту очереди */
	bool empty(queue& q_ref);

	/* функция проверки заполненности */
	bool full(queue& q_ref);

	/* добавление элемента в конец очереди */
	void add(queue& q_ref, Node* node);

	/* удаление первого элемента */
	Node* pop(queue& q_ref);

	/* функция вывода очереди на экран*/
	//void show(queue& q_ref);
}