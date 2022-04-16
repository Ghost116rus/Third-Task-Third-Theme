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
	/* ���� ��������� */
	struct my_List
	{
		int count = 1;					// ���������� ��������� � �������
		Node fix_arr[Array_Size+1];		// ��� ������
		Queue::queue free_array_cells;  // ������� ��������� ����� �������
	};

	/* ������� ������������� */
	void create(my_List& ml);

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
	/// <param name="m_l">�������� ������ �� ������<</param>
	/// <param name="find_data">�������� �������, ������� ���� �����</param>
	/// <param name="fcn">�������� �������, �� ������ �������� ����� ������</param>
	/// <returns>���������� ������ ���������� ��������</returns>
	int find_v2(my_List& m_l, int find_data, const std::function<bool(int, int)>& fcn);

	/// <summary>
	/// ������� ���������� ������ ��������
	/// </summary>
	/// <param name="m_l">�������� ������ �� ������</param>
	/// <param name="data">�������� ������, ������� ����� ��������</param>
	/// <param name="fcn">�������� �������, �� ������ �������� ����� ������</param>
	void add(my_List& m_l, int data, const std::function<bool(int, int)>& fcn);

	/// <summary>
	/// ������� �������� ��������
	/// </summary>
	/// <param name="m_l"></param>
	/// <param name="data">�������� ������, ������� ����� �������</param>
	void remove(my_List& m_l, int data);
}

