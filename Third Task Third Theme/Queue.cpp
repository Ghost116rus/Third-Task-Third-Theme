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
	return (q_ref.count == Array_Size-1);
}

void Queue::add(queue& q_ref, int data)
{
	if (full(q_ref))
	{
		std::cout << "Очередь переполнена!\n";
		return;
	}


	if (((q_ref.last_ptr + 1) - q_ref.start_of_arr) < (Array_Size-1))
	{
		*(q_ref.last_ptr++) = data;
	}
	else
	{
		*q_ref.last_ptr = data;
		q_ref.last_ptr = q_ref.start_of_arr;
	}
	q_ref.count++;
	//std::cout << "Добавление выполнено успешно.\n";
}

int Queue::pop(queue& q_ref)
{
	if (empty(q_ref))
	{
		std::cout << "Очередь пустая!\n";
		return -1;
	}

	int temp = *q_ref.first_ptr;
	*q_ref.first_ptr = 0;
	q_ref.first_ptr = q_ref.start_of_arr + ((q_ref.first_ptr + 1 - q_ref.start_of_arr) % (Array_Size-1));
	q_ref.count--;

	return temp;
	//std::cout << "Удаление выполнено успешно.\n";
}

void Queue::show(queue& q_ref)
{
	if (empty(q_ref))
	{
		std::cout << "Очередь пустая!\n";
		return;
	}

	int* temp_f = q_ref.first_ptr;
	int* temp_b = q_ref.start_of_arr;

	int i = 1;

	while (i != q_ref.count + 1)
	{
		std::cout << i++ << "-й\tэлемент очереди\t" << "данные:" << *temp_f << std::endl;
		temp_f = temp_b + (temp_f + 1 - temp_b) % (Array_Size-1);
	}
}
