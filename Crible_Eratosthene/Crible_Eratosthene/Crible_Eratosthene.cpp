// test_pointeur_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Linked_List.h"
#include "Main.h"
#include "User_Layer.h"

int main()
{
	int max = user_layer::ask_for_number("enter max number : ");

	node* list = node::init_node();
	main::fill_list(&list, max);
	main::crible_eratosthene(&list);
	main::display_list(list);

}

void(main::fill_list)(node** list_head, int max_int)
{
	if ((*list_head) == nullptr)
	{
		(*list_head) = node::init_node();
	}
	int flag = 0;
	for (int i = 2; i <= max_int; i++)
	{
		flag = i;
		(*list_head)->push_back((*list_head), &flag, sizeof(int));
	}
}

void(main::remove_multiple_of)(node** list_head, int multiple)
{
	node* p_head = (*list_head);

	while (p_head != nullptr)
	{
		if ((*static_cast<int*>(p_head->m_data)) != multiple && (*static_cast<int*>(p_head->m_data) % multiple) == 0)
		{
			node* next_of_next = p_head->m_next;
			(p_head->remove_node(list_head, p_head));
			p_head = next_of_next;
		}
		else
			p_head = p_head->m_next;
	}
}

void(main::display_list)(node* list_head)
{
	while (list_head != nullptr && list_head->m_data != nullptr)
	{
		printf("%d\n", *static_cast<int*>(list_head->m_data));
		list_head = list_head->m_next;
	}
}

void(main::crible_eratosthene)(node ** list_head)
{
	node* p_cursor = (*list_head);

	while (p_cursor != nullptr && p_cursor->m_next != nullptr)
	{
		main::remove_multiple_of(list_head, *static_cast<int*>(p_cursor->m_data));
		p_cursor = p_cursor->m_next;
	}
}