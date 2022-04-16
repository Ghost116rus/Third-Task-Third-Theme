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

	/* ������� ������������� ������� */
	void init(queue& q_ref);

	/* ������� �������� �� ������� ������� */
	bool empty(queue& q_ref);

	/* ������� �������� ������������� */
	bool full(queue& q_ref);

	/* ���������� �������� � ����� ������� */
	void add(queue& q_ref, Node* node);

	/* �������� ������� �������� */
	Node* pop(queue& q_ref);

	/* ������� ������ ������� �� �����*/
	//void show(queue& q_ref);
}