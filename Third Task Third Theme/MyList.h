#pragma once
#include <iostream>
#include <functional>
//#include "Queue.h"


enum MyEnum
{
	Not_found = -1,
	Find_el,
};

const int Array_Size = 9;

namespace MYLIST
{
	/* ������� ������� ������ */
	struct Node
	{
		int data = 0;
		int next_ptr = NULL;
	};

	struct Stack
	{
		int next_ptr = NULL;
	};

	/* ���� ��������� */
	struct my_List
	{
		int count = 1;					// ���������� ��������� � �������
		Node fix_arr[Array_Size];		// ��� ������
		//Queue::queue free_array_cells;  // ������� ��������� ����� �������
	};

	/* ������� ������������� */
	void init(my_List& ml, Node& stack);

	/// <summary>
	/// ������� ������ ������ �� ����
	/// </summary>
	/// <param name="m_l">�������� ������ �� ������</param>
	void show(my_List& m_l);

	/// <summary>
	/// ������� �������� ������ �� �������������  
	/// </summary>
	/// <param name="m_l">�������� ������ �� ������</param>
	/// <returns>���������� ������� ��������� - ����� �� ������</returns>
	bool full(my_List& m_l);

	/// <summary>
	/// ������� �������� ������ �� �������  
	/// </summary>
	/// <param name="m_l">�������� ������ �� ������</param>
	/// <returns>���������� ������� ��������� - ���� �� ������</returns>
	bool empty(my_List& m_l);


	/// <summary>
	/// ������� ������ ��������� ��������
	/// </summary>
	/// <param name="m_l">�������� ������ �� ������</param>
	/// <param name="find_data">�������� �������, ������� ���� �����</param>
	/// <returns>���������� ������ ���������� ��������</returns>
	int find_v2(my_List& m_l, int find_data);

	/// <summary>
	/// ������� ���������� ������ �������� � ������
	/// </summary>
	/// <param name="m_l">�������� ������ �� ������</param>
	/// <param name="find_data">����������� ������</param>
	void push_front(my_List& m_l, int data, Node& stack);


	/// <summary>
	/// ������� ���������� ������ ��������
	/// </summary>
	/// <param name="m_l">�������� ������ �� ������</param>
	/// <param name="data">����������� ������</param>
	/// <param name="find_data">���� ������������ �������� � ������ �������</param>
	/// <param name="after">�������� �� ������������ ������ �������� ��/����� ���������</param>
	void add(my_List& m_l, int data, int find_data, bool after, Node& stack);

	/// <summary>
	/// ������� �������� ��������
	/// </summary>
	/// <param name="m_l"></param>
	/// <param name="data">�������� ������, ������� ����� �������</param>
	void remove(my_List& m_l, int find_data, Node& stack);
}
