#pragma once
struct node
{
	void* m_data;
	node* m_next;

	// construct
	static node* (init_node)();

	// method
	void (push_back)(node* head, void* data, size_t data_size);
	void (remove_node)(node ** head, node * to_remove);
	node* (get_last_nodes)(node* head);
};