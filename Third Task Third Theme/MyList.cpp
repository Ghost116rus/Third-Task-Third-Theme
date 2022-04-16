#include "MyList.h"


void MYLIST::create(my_List& ml)
{
	// Для первой ячейки делаем уникальные данные
	ml.fix_arr[0].data = -1;
	ml.fix_arr[0].next_ptr = NULL;
	
	/* Инициализируем очередь */
	Queue::init(ml.free_array_cells);

	// Заносим все свободные ячейки в очередь
	for (size_t i = 1; i < Array_Size; i++)
	{
		Queue::add(ml.free_array_cells, i);
		ml.fix_arr[i].data = 0;
		ml.fix_arr[i].next_ptr = NULL;
	}
}

void MYLIST::show(my_List& m_l)
{
	int i = 1;
	int current = m_l.fix_arr[0].next_ptr;

	// Обычный проход по циклу
	while (current)
	{
		std::cout << i++ << "-ый элемент списка\t Данные: "
			<< m_l.fix_arr[current].data << std::endl;
		current = m_l.fix_arr[current].next_ptr;
	}
}

bool MYLIST::full(my_List& m_l)
{
	return m_l.count == Array_Size;
}

bool MYLIST::empty(my_List& m_l)
{
	return !(m_l.count-1);
}

int MYLIST::find_v2(my_List& m_l, int find_data)
{
	int current = 0;
	do
	{
		if (find_data == m_l.fix_arr[m_l.fix_arr[current].next_ptr].data)
		{
			return current;
		}
		current = m_l.fix_arr[current].next_ptr;
	} while (current);

	return Not_found;
}

void MYLIST::add(my_List& m_l, int data, int find_data, bool after)
{
	if (MYLIST::empty(m_l))
	{
		m_l.fix_arr[0].next_ptr = Queue::pop(m_l.free_array_cells);
		m_l.fix_arr[m_l.fix_arr[0].next_ptr].data = data;

		m_l.count++; std::cout << "Добавление выполнено успешно\n";
		return;
	}
	else if (MYLIST::full(m_l))
	{
		std::cout << "Список переполнен!\n";
	}

	int current_i = MYLIST::find_v2(m_l, find_data);

	if (current_i != Not_found)
	{
		if (after)
		{
			current_i = m_l.fix_arr[current_i].next_ptr;
		}

		int temp_i = m_l.fix_arr[current_i].next_ptr;
		m_l.fix_arr[current_i].next_ptr = Queue::pop(m_l.free_array_cells);

		m_l.fix_arr[m_l.fix_arr[current_i].next_ptr].next_ptr = temp_i;
		m_l.fix_arr[m_l.fix_arr[current_i].next_ptr].data = data;

		m_l.count++; std::cout << "Добавление выполнено успешно\n";
	}
	else
	{
		std::cout << "Заданный элемент не был найден!\n";
	}
}

void MYLIST::remove(my_List& m_l, int find_data)
{
	if (MYLIST::empty(m_l))
	{
		std::cout << "Список пустой!\n"; return;
	}


	int current_i = MYLIST::find_v2(m_l, find_data);

	if (current_i != Not_found)
	{
		int temp = m_l.fix_arr[current_i].next_ptr;

		m_l.fix_arr[temp].data = 0;
		m_l.fix_arr[current_i].next_ptr = m_l.fix_arr[temp].next_ptr;
		m_l.fix_arr[temp].next_ptr = 0;

		m_l.count--; std::cout << "Удаление выполнено успешно\n";
	}
	else
	{
		std::cout << "Заданный элемент не был найден!\n";
	}

}
