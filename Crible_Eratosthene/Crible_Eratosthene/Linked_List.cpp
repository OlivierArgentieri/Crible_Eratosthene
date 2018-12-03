#include "pch.h"
#include "Linked_List.h"
#include <cstdlib>
#include <cstring>

node*(node::init_node)()
{
	node* n = (node*)malloc(sizeof(node));
	n->m_data = nullptr;
	n->m_next = nullptr;

	return n;
}

void node::push_back(node* head, void* data, size_t data_size)
{
	if (head->m_data == nullptr)
	{
		head->m_data = malloc(data_size);
		memcpy(head->m_data, data, data_size);
		return;
	}

	node* last_node = get_last_nodes(head);

	last_node->m_next = node::init_node();
	last_node->m_next->m_data = malloc(data_size);
	memcpy(last_node->m_next->m_data, data, data_size);
}

void node::remove_node(node** head, node* to_remove)
{
	if ((*head) == nullptr)
		return;

	if ((*head) == to_remove)
	{
		node* p_flag = (*head)->m_next;
		free((*head));
		(*head) = p_flag;
		return;
	}

	node* flag = (node*)malloc(sizeof(node));
	memcpy(flag, (*head), sizeof(node));
	while (flag != nullptr && flag->m_next != nullptr && to_remove != flag->m_next)
	{
		flag = flag->m_next;
	}

	if (to_remove == flag->m_next)
	{
		node* p_flag = flag->m_next;
		flag->m_next = flag->m_next->m_next;
		free(p_flag);
	}
}

node* node::get_last_nodes(node* head)
{
	while (head != nullptr && head->m_next != nullptr)
	{
		head = head->m_next;
	}
	return head;
}
