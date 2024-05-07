#pragma once
// Node Definition
template <typename Item_Type>
struct Node {
	Item_Type data;
	Node<Item_Type>* next_ptr;
};

// Class Decleration
template <typename t> class single_linked {
private:
	Node<t> *Head_Ptr, *Tail_Ptr;
	size_t num_items;

public:
	// Defualt Constructor:
	single_linked();

	// Print List Function
	void printList();

	// Push Functions
	bool push_front(const t& item);
	bool push_back(const t& item);

	// Pop Functions
	bool pop_front();
	bool pop_back();

	// Info functions:
	t& front();
	t& back();
	bool empty();

	// Targeted Functions:
	void insert(size_t index, const t& item);
	bool remove(size_t index);
	size_t find(const t& item);
};