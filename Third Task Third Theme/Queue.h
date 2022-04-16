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

	/* ������� ������������� ������� */
	void init(queue& q_ref);

	/* ������� �������� �� ������� ������� */
	bool empty(queue& q_ref);

	/* ������� �������� ������������� */
	bool full(queue& q_ref);

	/* ���������� �������� � ����� ������� */
	void add(queue& q_ref, int data);

	/* �������� ������� �������� */
	int pop(queue& q_ref);

	/* ������� ������ ������� �� �����*/
	void show(queue& q_ref);
}