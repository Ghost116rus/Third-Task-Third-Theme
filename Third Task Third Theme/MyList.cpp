#include "MyList.h"

using namespace MYLIST;

void MYLIST::init(my_List& ml, Node& stack)
{
	// Для первой ячейки делаем уникальные данные
	ml.fix_arr[0].data = -1;
	ml.fix_arr[0].next_ptr = NULL;
	
	///* Инициализируем очередь */
	//Queue::init(ml.free_array_cells);
	stack.next_ptr = 8;

	// Заносим все свободные ячейки в очередь
	for (size_t i = 1; i < Array_Size; i++)
	{
		
		//Queue::add(ml.free_array_cells, i);
		ml.fix_arr[i].data = 0;
		ml.fix_arr[i].next_ptr = i-1;
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
	// из-за того, что я возвращаю указатель на элемент, стоящий до того, который я ищу, пришлось использовать do
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

int pop(my_List& m_l, MYLIST::Node& stack)
{
	int current = stack.next_ptr;
	stack.next_ptr = m_l.fix_arr[current].next_ptr;

	return current;
}

void addS(my_List& m_l, MYLIST::Node& stack, int index)
{
	m_l.fix_arr[index].next_ptr = stack.next_ptr;
	stack.next_ptr = index;
}


void MYLIST::push_front(my_List& m_l, int data, Node& stack)
{
	if (MYLIST::empty(m_l))
	{
		int temp = m_l.fix_arr[0].next_ptr;
		m_l.fix_arr[0].next_ptr = pop(m_l, stack);
		m_l.fix_arr[m_l.fix_arr[0].next_ptr].data = data;
		m_l.fix_arr[m_l.fix_arr[0].next_ptr].next_ptr = temp;

		m_l.count++; std::cout << "Добавление выполнено успешно\n";
		return;
	}
}




void MYLIST::add(my_List& m_l, int data, int find_data, bool after, Node& stack)
{
	/*if (MYLIST::empty(m_l))
	{
		push_front(m_l, data);
		return;
	}*/

	if (MYLIST::full(m_l))
	{
		std::cout << "Список переполнен!\n";
	}

	int current_i = MYLIST::find_v2(m_l, find_data);

	if (current_i != Not_found)
	{
		if (after)
		{
			// В случае, если нужно вставить после искомого, мы сразу берем следующий индекс
			current_i = m_l.fix_arr[current_i].next_ptr;
		}

		int temp_i = m_l.fix_arr[current_i].next_ptr;
		m_l.fix_arr[current_i].next_ptr = pop(m_l, stack);

		m_l.fix_arr[m_l.fix_arr[current_i].next_ptr].next_ptr = temp_i;
		m_l.fix_arr[m_l.fix_arr[current_i].next_ptr].data = data;

		m_l.count++; std::cout << "Добавление выполнено успешно\n";
	}
	else
	{
		std::cout << "Заданный элемент не был найден!\n";
	}
}

void MYLIST::remove(my_List& m_l, int find_data, Node& stack)
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

		addS(m_l, stack, temp);
		m_l.count--; std::cout << "Удаление выполнено успешно\n";
	}
	else
	{
		std::cout << "Заданный элемент не был найден!\n";
	}

}
