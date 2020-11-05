#ifndef CS20A_LIST_H
#define CS20A_LIST_H

#include<iostream>
#include<assert.h>
// Linked List object that maintains both m_head and m_tail pointers
// and the m_size of the list.  Note that you have to keep the m_head,
// m_tail and m_size consistent with the intended state of the List
// otherwise very bad things happen.
template<typename Item>
class List {
public:

	List();

	List(const List<Item>& other);

	List<Item>& operator=(const List<Item>& other);

	~List();

	void	print() const;
	bool	empty() const;

	void	push_front(const Item& item);
	void	push_rear(const Item& item);
	void	insert(int index, const Item& item);

	// Note that the user must first ensure the list is not empty
	// prior to calling these functions.
	Item	front() const;
	Item	rear() const;
	Item	get(int index) const;

	int		size() const;
	int		find(const Item& item) const;

	bool	pop_front();
	bool	pop_rear();
	bool	remove(int index);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	// Forward declare the nodes for our List.
	// Will be implemented along with list's
	// member functions
	struct Node;

	// We'll have both m_head and m_tail points for
	// Fast insertion/deletion from both ends.
	Node* m_head;
	Node* m_tail;

	// Keep track of number of nodes in the list
	int		m_size;
};

/* List Implementation
//
//  Since List is a template class (which is not an actual
//  class yet, not until we actually instantiate the list)
//  we need to keep the implementation together with
//  the definition.  There are ways to simulate having
//  separate "implementation/definition" with templates,
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//		Already implemented, nothing to do here but to use it.
*/
template<typename Item>
struct List<Item>::Node {
	Node() :next(nullptr), prev(nullptr) {}
	Node(Item it, Node* p, Node* n) : item(it), next(n), prev(p) {}

	Item  item;
	Node* next;
	Node* prev;
};

/* List default constructor
//		Set m_head and m_tail pointer to point to nothing, m_size is zero
//		Already implemented, nothing to do.
*/
template<typename Item>
List<Item>::List() :m_head(nullptr), m_tail(nullptr), m_size(0) {
}

/* Copy constructor
*/
template<typename Item>
List<Item>::List(const List<Item>& other) {
	m_size = other.m_size;
	if (m_size == 0)
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	else if (m_size == 1)
	{
		Node* temp_node = new Node();
		m_head = temp_node;
		m_tail = temp_node;
	}
	else
	{
		m_head = new Node();
		Node* temp = m_head;
		Node* other_list = other.m_head;
		for (int i = 0; i < m_size; i++)
		{
			temp->item = other_list->item;
			if (other_list->next != nullptr)
			{
				Node* new_node = new Node();
				new_node->prev = temp;
				temp->next = new_node;
				temp = new_node;
				other_list = other_list->next;
			}
			else
			{
				m_tail = temp;
			}
		}
	}
}
/* Overloaded assignment operator
*/
template<typename Item>
List<Item>& List<Item>::operator=(const List<Item>& other) {
	Node* other_list = other.m_head;
	Node* temp;
	if (other.m_head == nullptr)
	{
		this->m_size = 0;
		this->m_head = nullptr;
		this->m_tail = nullptr;
		return *this;
	}
	this->m_size = other.m_size;
	if (other.m_size == 1)
	{
		Node* temp_node = new Node();
		temp_node->item = other_list->item;
		this->m_head = temp_node;
		this->m_tail = temp_node;
		return *this;
	}
	this->m_head = new Node();
	temp = this->m_head;

	for (int i = 0; i < this->m_size; i++)
	{
		temp->item = other_list->item;
		if (other_list->next != nullptr)
		{
			Node* new_node = new Node();
			new_node->prev = temp;
			temp->next = new_node;
			temp = new_node;
			other_list = other_list->next;
		}
		else
		{
			this->m_tail = temp;
		}
	}
	return *this;
}

/* List destructor
*/
template<typename Item>
List<Item>::~List() {
	Node* next;
	while (m_head != nullptr)
	{
		next = m_head->next;
		delete(m_head);
		m_head = next;
	}
}

/* List print
*/
template<typename Item>
void List<Item>::print() const {
	Node* temp = m_head;
	std::cout << "link of " << m_size << "\n";
	while (temp != nullptr)
	{
		std::cout << temp->item << " ";
		if (temp->next == nullptr)
		{
			std::cout << temp->item;
		}
		temp = temp->next;
	}
	std::cout << "\n";
}

/* List empty
*/
template<typename Item>
bool List<Item>::empty() const {
	/* TODO */
	if (m_head == nullptr)
	{
		return true;
	}
	return false;
}

/* List push_front
*/
template<typename Item>
void List<Item>::push_front(const Item& item) {
	Node* new_node = new Node();
	new_node->item = item;
	if (m_head == nullptr)
	{
		m_head = new_node;
		m_tail = new_node;
		m_size += 1;
	}
	else {
		m_head->prev = new_node;
		new_node->next = m_head;
		m_head = new_node;
		m_size += 1;
	}
}

/* List push_rear
*/
template<typename Item>
void List<Item>::push_rear(const Item& item) {
	Node* new_node = new Node();
	new_node->item = item;
	if (m_head == nullptr)
	{
		m_head = new_node;
		m_tail = new_node;
		m_size += 1;
	}
	else
	{
		Node* rear_node = m_tail;
		rear_node->next = new_node;
		new_node->prev = rear_node;
		m_tail = new_node;
		m_size += 1;
	}
}

/* List insert
*/
template<typename Item>
void List<Item>::insert(int index, const Item& item) {
	int count = 0;
	Node* temp_node = m_head;
	Node* new_node = new Node();
	new_node->item = item;
	if (m_size <= 0)
	{
		m_head = new_node;
		m_tail = new_node;
		m_size += 1;
	}
	else if (index >= m_size)
	{
		Node* rear_node = m_tail;
		rear_node->next = new_node;
		new_node->prev = rear_node;
		m_tail = new_node;
		m_size += 1;
	}
	else if (index <= 0)
	{
		push_front(item);
	}
	else
	{
		while (count < index)
		{
			temp_node = temp_node->next;
			count++;
		}
		Node* old_node = temp_node->next;
		old_node->prev = new_node;
		new_node->prev = temp_node;
		new_node->next = old_node;
		temp_node->next = new_node;
		m_size += 1;
	}
}

/*  List front
*/
template<typename Item>
Item List<Item>::front() const {
	// Force check that the m_head is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(m_head != nullptr);
	Item item = m_head->item;
	return item;
}

/* List rear
*/
template<typename Item>
Item List<Item>::rear() const {
	// Force check that the m_tail is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(m_tail != nullptr);
	Item item = m_tail->item;
	return item;
}

/* List get
//		returns the item at index
*/
template<typename Item>
Item List<Item>::get(int index) const {
	// Force index to be correct before getting the Item
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(index >= 0 && index < m_size);
	Node* temp = m_head;
	int count = 0;
	while (count < index)
	{
		temp = temp->next;
		count++;
	}
	Item item = temp->item;
	return item;
}

/* List size
*/
template<typename Item>
int List<Item>::size() const {
	return m_size;
}

/* List find
*/
template<typename Item>
int List<Item>::find(const Item& item) const {
	Node* temp = m_head;
	int index = -1;
	for (int i = 0; i < m_size; i++)
	{
		if (item != temp->item)
		{
			temp = temp->next;
			i++;
		}
		else
		{
			index = i;
		}
	}
	return index;
}

/* List pop_front
*/
template<typename Item>
bool List<Item>::pop_front() {
	if (m_size <= 0)
	{
		return false;
	}
	if (m_size < 2)
	{
		delete(m_head);
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
		return true;
	}
	Node* adjecent_node = m_head->next;
	adjecent_node->prev = nullptr;
	delete(m_head);
	m_head = adjecent_node;
	m_size -= 1;
	return true;
}

/* List pop_rear
*/
template<typename Item>
bool List<Item>::pop_rear() {
	if (m_size <= 0)
	{
		return false;
	}
	if (m_size < 2)
	{
		delete(m_head);
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
		return true;
	}
	Node* left_adjecent_node = m_tail->prev;
	left_adjecent_node->next = nullptr;
	delete(m_tail);
	m_tail = left_adjecent_node;
	m_size -= 1;
	return true;
}

/* List remove
*/
template<typename Item>
bool List<Item>::remove(int index) {
	if (index >= 0 && index <= m_size && m_size != 0)
	{
		if (m_size == 1)
		{
			delete(m_head);
			m_head = nullptr;
			m_tail = nullptr;
			m_size = 0;
			return true;
		}
		if (m_size == 2)
		{
			int counter = 0;
			Node* temp_head = m_head;
			while (counter < index)
			{
				temp_head = temp_head->next;
				counter++;
			}
			Node* left_adject = temp_head->prev;
			left_adject->next = nullptr;
			delete(temp_head);
			m_tail = left_adject;
			m_size -= 1;
			return true;
		}
		if (index == 0)
		{
			Node* new_head = m_head->next;
			new_head->prev = nullptr;
			delete(m_head);
			m_head = new_head;
			m_size -= 1;
			return true;
		}
		int count = 0;
		Node* temp = m_head;
		while (count < index)
		{
			temp = temp->next;
			count++;
		}
		Node* left_adjecent = temp->prev;
		if (temp->next != nullptr)
		{
			Node* right_adjecent = temp->next;
			left_adjecent->next = right_adjecent;
			right_adjecent->prev = left_adjecent;
			delete(temp);
			m_size -= 1;
			return true;
		}
		left_adjecent->next = nullptr;
		delete(temp);
		m_tail = left_adjecent;
		m_size -= 1;
		return true;
	}
	return false;
}

#endif // _X_XMMXX