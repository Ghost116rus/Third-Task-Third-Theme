#include "MyList.h"


void MYLIST::create(my_List& ml)
{
	// ƒл€ первой €чейки делаем уникальные данные
	ml.fix_arr[0].data = -1;
	ml.fix_arr[0].next_ptr = NULL;
	
	/* »нициализируем очередь */
	Queue::init(ml.free_array_cells);

	// «аносим все свободные €чейки в очередь
	for (size_t i = 1; i < Array_Size; i++)
	{
		Queue::add(ml.free_array_cells, &(ml.fix_arr[i]));
		ml.fix_arr[i].data = 0;
		ml.fix_arr[i].next_ptr = NULL;
	}
}

void MYLIST::show(my_List& m_l)
{

}

bool MYLIST::full(my_List& m_l)
{
	return m_l.count == Array_Size;
}

bool MYLIST::empty(my_List& m_l)
{
	return !(m_l.count-1);
}

int MYLIST::find_v2(my_List& m_l, int find_data, const std::function<bool(int, int)>& fcn)
{
	return 0;
}

void MYLIST::add(my_List& m_l, int data, const std::function<bool(int, int)>& fcn)
{
	if (MYLIST::empty(m_l))
	{
		m_l.fix_arr[0].next_ptr = Queue::pop(m_l.free_array_cells);

	}
}

void MYLIST::remove(my_List& m_l, int data)
{

}
