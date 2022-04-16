#include "Queue.h"


using namespace Queue;

void Queue::init(queue& q_ref)
{
	q_ref.first_ptr = q_ref.fixed_array;
	q_ref.last_ptr = q_ref.fixed_array;
	q_ref.start_of_arr = q_ref.fixed_array;

	q_ref.count = 0;
}

bool Queue::empty(queue& q_ref)
{
	return !q_ref.count;
}

bool Queue::full(queue& q_ref)
{
	return (q_ref.count == 5);
}

void Queue::add(queue& q_ref, Node*  node)
{
	if (full(q_ref))
	{
		std::cout << "Список пуст!\n";
		return;
	}


	if (((q_ref.last_ptr + 1) - q_ref.start_of_arr) < 5)
	{
		*(q_ref.last_ptr++) = node;
	}
	else
	{
		*q_ref.last_ptr = node;
		q_ref.last_ptr = q_ref.start_of_arr;
	}
	q_ref.count++;
	//std::cout << "Добавление выполнено успешно.\n";
}

Node* Queue::pop(queue& q_ref)
{
	if (empty(q_ref))
	{
		std::cout << "Список переполнен!\n";
		return;
	}

	Node* temp = *q_ref.first_ptr;
	q_ref.first_ptr = q_ref.start_of_arr + ((q_ref.first_ptr + 1 - q_ref.start_of_arr) % 5);
	q_ref.count--;

	return temp;
	//std::cout << "Удаление выполнено успешно.\n";
}

/*
void Queue::show(queue& q_ref)
{
	if (empty(q_ref))
	{
		std::cout << "Очередь пустая!\n";
		return;
	}

	MYLIST::Node* temp_f = q_ref.first_ptr;
	MYLIST::Node* temp_b = q_ref.start_of_arr;

	int i = 1;

	while (i != q_ref.count + 1)
	{
		std::cout << i++ << "-й\tэлемент очереди\t" << "данные:" << *temp_f << std::endl;
		temp_f = temp_b + (temp_f + 1 - temp_b) % 5;
	}
}
*/