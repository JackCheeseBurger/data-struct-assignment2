#include "s_linked.h"
#include <iostream>

// Constructor:

template<typename t>
single_linked<t>::single_linked()
{
	Head_Ptr = nullptr, Tail_Ptr = nullptr;
	num_items = 0;
}

// Push Functions:

template<typename t>
bool single_linked<t>::push_front(const t& item)
{
	Node<t>* tmp = new Node<t>;
	tmp->data = item;
	if (Head_Ptr == nullptr) {
		Head_Ptr = tmp;
		Tail_Ptr = tmp;
	}
	else {
		tmp->next_ptr = Head_Ptr;
		Head_Ptr = tmp;
	}
	return true;
}

template<typename t>
bool single_linked<t>::push_back(const t& item)
{
	Node<t>* tmp = new Node<t>;
	tmp->data = item;
	if (Head_Ptr == nullptr) {
		Head_Ptr = tmp;
		Tail_Ptr = tmp;
	}
	else {
		Tail_Ptr->next_ptr = tmp;
		Tail_Ptr = tmp;
	}
	return true;
}

// Pop Functions:

template<typename t>
bool single_linked<t>::pop_front()
{
	if (Head_Ptr == nullptr) {
		return false;
	}
	Node<t>* tmp = Head_Ptr;
	Head_Ptr = Head_Ptr->next_ptr;
	free(tmp);
	num_items -= 1;
	return true;
}

template<typename t>
bool single_linked<t>::pop_back()
{
	if (Head_Ptr == nullptr) {
		return false;
	}
	Node<t>* current = Head_Ptr;
	while (current->next_ptr != Tail_Ptr) {
		current = current->next_ptr;
	}
	free(Tail_Ptr);
	Tail_Ptr = current;
	num_items -= 1;
	return true;
}

// Info Functions:

template<typename t>
t& single_linked<t>::front()
{
	return Head_Ptr->data;
}

template<typename t>
t& single_linked<t>::back()
{
	return Tail_Ptr->data;
}

template<typename t>
bool single_linked<t>::empty()
{
	if (Head_Ptr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

// Targeted Functions:

template<typename t>
void single_linked<t>::insert(size_t index, const t& item)
{
	if (index > num_items) {
		push_back(item);
		return;
	}
	else if (index == 0) {
		push_front(item);
	}else {
		Node<t>* tmp = new Node<t>;
		tmp->data = item;
		Node<t>* current = Head_Ptr;
		for (int i = 0; i < index - 1; i++) {
			current = current->next_ptr;
		}
		tmp->next_ptr = current->next_ptr;
		current->next_ptr = tmp;
		if (index == num_items - 1) {
			Tail_Ptr = tmp;
		}
		num_items += 1;
		return;
	}
}

template<typename t>
bool single_linked<t>::remove(size_t index)
{
	if (index > num_items) {
		return false;
	}
	else if (index == 0) {
		pop_front();
		return true;
	}
	else if (index == num_items - 1) {
		pop_back();
		return true;
	}
	else {
		Node<t>* current = Head_Ptr;
		for (int i = 0; i < index - 1; i++) {
			current = current->next_ptr;
		}
		Node<t>* tmp = current->next_ptr;
		current->next_ptr = current->next_ptr->next_ptr;
		free(tmp);
		num_items -= 1;
		return true;
	}
}

template<typename t>
size_t single_linked<t>::find(const t& item)
{
	Node<t>* current = Head_Ptr;
	int i = 0;
	while(current->next_ptr != nullptr){
		if (current->data == item) {
			return i;
		}
		current = current->next_ptr;
		i += 1;
	}
	return num_items;
}

// End of member Functions.
