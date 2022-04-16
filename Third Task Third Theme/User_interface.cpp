#include "user_interface.h"


int getValue(int condition, const char* string)
{
	while (true)													// ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// ���� ���������� ���������� ��������� ���������,
		{
			std::cout << "������! ����������, ��������� ����! \n";
			std::cin.clear();										// �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n');							// � ������� �������� ����������� ����� �� �������� ������
			std::cout << string;
		}
		else // ���� �� ������ � ���������� �������, �� ���������� a
		{
			switch (condition)
			{
			case Natural_number:
				if (a > 0) { return a; }

				std::cout << "�� ������ ������ ����������� �����\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case O_Or_1:												// �� �������

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "�� ������ ������ ���� 0, ���� 1\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case Menu_Commands:

				if (((int)a > 0) && ((int)a < 8)) { return a; }

				std::cout << "� ���� ����� 7 �������! ��������� ����: ";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout << "  ���������� ���������:\n"
		<< "1. ������������� ������\n"
		<< "2. ���������� ������ ��������\n"
		<< "3. �������� �������� ������\n"
		<< "4. �������� ���������� ������\n"
		<< "5. �������� ������� ����\n"
		<< "6. ������� ������ ���������\n"
		<< "\n7. ���������� ������\n\n";
}

void write_author()
{
	std::cout << "������ �������� ������ �.�., ������ 4211\n";
}



void menu(MYLIST::my_List& my_list)
{
	int user_choice = 0;
	bool complete_init = false;

	show_main_menu();
	std::cout << "�������� �������: ";
	user_choice = getValue(Menu_Commands, "�������� �������: ");

	while (user_choice != Exit)
	{
		int temp_data;
		switch (user_choice)
		{

		case Init:

			if (!complete_init)
			{
				MYLIST::init(my_list); std::cout << "C����� ���������������.\n";
				complete_init = true;
			}
			else
			{
				std::cout << "C����� ��� ���������������!\n";
			}
			break;

		case Add_new_element:

			if (complete_init)
			{
				if (!(MYLIST::full(my_list)))
				{
					std::cout << "�������, ������ ������� ������ ��������: ";
					temp_data = getValue(1, "������� ������: ");

					if ((MYLIST::empty(my_list)))
					{
						MYLIST::push_front(my_list, temp_data);
					}
					else
					{
						std::cout << "������� �������, �� �������� �� ����� �������������: ";
						int find_data = getValue(Natural_number, "������� �������, �� �������� �� ����� �������������: ");

						std::cout << "�� ������ �������� ������ �� ��������� �������� ��� �����? 0 - ��, 1 - �����\n �������: ";
						int after = getValue(O_Or_1, "�� ������ �������� ������ �� ��������� �������� ��� �����? 0 - ��, 1 - �����\n �������: ");

						MYLIST::add(my_list, temp_data, find_data, after);
					}
					
				}
				else
				{
					std::cout << "������ ����������.\n";
				}

			}
			else
			{
				std::cout << "���������� ��������� ��������, �.� ������ �� ���������������\n";
			}

			break;

		case Delete_element:

			if (complete_init)
			{
				if (MYLIST::empty(my_list))
				{
					std::cout << "������ ������!\n";
				}
				else
				{
					std::cout << "������� ������, ������� ������ �� �������: ";
					temp_data = getValue(1, "������� ������: ");
					MYLIST::remove(my_list, temp_data);
				}

			}
			else
			{
				std::cout << "���������� ���-���� �������, �.� ������ �� ���������������!\n";
			}


			break;

		case Show_list:

			if (complete_init) { MYLIST::show(my_list); }
			else { std::cout << "������ �� ���������������!\n"; }

			break;

		case Show_main_menu:

			std::cout << "\n\n";
			show_main_menu();
			break;

		case Write_author:

			write_author();
			break;

		default:
			break;
		}
		std::cout << "\n�������� �������: ";
		user_choice = getValue(Menu_Commands, "�������� �������: ");
	}

	std::cout << "���������� ������\n";
}