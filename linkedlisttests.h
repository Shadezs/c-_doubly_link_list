#ifndef PROJECT3_LLTEST_H
#define PROJECT3_LLTEST_H
#define MAKE_MEMBERS_PUBLIC

#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<iterator>
#include<vector>
#include<assert.h>
#include"list.h"
#ifdef _MSC_VER // Visual Studio

#define __func__ __FUNCTION__

#ifndef debugnew
#define debugnew new
#endif

#endif

#include"debugmem.h"

//Test empty
int test_empty(int testNum) {
	std::cout << __func__ << testNum << std::endl;

	switch (testNum) {
	case 0: {
		List<int> l;

		assert(l.empty() == true);

		break;
	}
	case 1: {
		//Make some control nodes
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.empty() == false);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//Test push_front
int test_push_front(int testNum) {
	std::cout << __func__ << testNum << std::endl;

	switch (testNum) {
	case 0: {
		List<int> l;

		l.push_front(99);

		assert(l.m_head->prev == nullptr);
		assert(l.m_head->next == nullptr);
		assert(l.m_head != nullptr);
		assert(l.m_tail != nullptr);
		assert(l.m_head->item == 99);
		assert(l.m_size == 1);

		break;
	}
	case 1: {
		//Make some control nodes
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for push_front;
		l.push_front("Zero");

		//Examing the final state of our list after call
		assert(l.m_size == 4);
		assert(l.m_head->prev == nullptr);
		assert(l.m_head == first->prev);
		assert(l.m_head->next == first);
		assert(l.m_head->item == "Zero");
		assert(l.m_tail == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//Test push_rear
int test_push_rear(int testNum) {
	std::cout << __func__ << testNum << std::endl;

	switch (testNum) {
	case 0: {
		List<int> l;

		l.push_rear(99);

		assert(l.m_head->prev == nullptr);
		assert(l.m_head->next == nullptr);
		assert(l.m_head != nullptr);
		assert(l.m_tail != nullptr);
		assert(l.m_head->item == 99);
		assert(l.m_size == 1);
		break;
	}
	case 1: {
		//Make some control nodes
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for push_rear;
		l.push_rear("forth");

		//Examing the final state of our list after call
		assert(l.m_size == 4);
		assert(l.m_head == first);
		assert(l.m_tail->next == nullptr);
		assert(l.m_tail->item == "forth");
		assert(l.m_tail->prev == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//Test insert
int test_insert(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<int> l;

		l.insert(0, 1);

		assert(l.m_size == 1);
		assert(l.m_head->item == 1);
		assert(l.m_head == l.m_tail);
		assert(l.m_head != nullptr);
		assert(l.m_tail != nullptr);
		assert(l.m_head->next == nullptr);
		assert(l.m_head->prev == nullptr);
		break;
	}
	case 1: {
		List<int> l;

		l.insert(-1, 1);

		assert(l.m_size == 1);
		assert(l.m_head->item == 1);
		assert(l.m_head == l.m_tail);
		assert(l.m_head != nullptr);
		assert(l.m_tail != nullptr);
		assert(l.m_head->next == nullptr);
		assert(l.m_head->prev == nullptr);
		break;
	}
	case 2: {
		List<int> l;

		l.insert(99, 1);

		assert(l.m_head->item == 1);
		assert(l.m_size == 1);
		assert(l.m_head == l.m_tail);
		assert(l.m_head != nullptr);
		assert(l.m_tail != nullptr);
		assert(l.m_head->next == nullptr);
		assert(l.m_head->prev == nullptr);
		break;
	}
	case 3: {
		//Make some control nodes
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = second;
		l.m_size = 2;

		l.insert(0, "Zero");

		//Examing the final state of our list after call
		//assert(l.m_head != nullptr);
		assert(l.m_size == 3);
		assert(l.m_head->prev == nullptr);
		assert(l.m_head == first->prev);
		assert(l.m_head->next == first);
		assert(l.m_head->item == "Zero");
		assert(l.m_tail == second);

		break;
	}
	case 4: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = second;
		l.m_size = 2;

		l.insert(-1, "Zero");

		//Examing the final state of our list after call
		assert(l.m_size == 3);
		assert(l.m_head->prev == nullptr);
		assert(l.m_head == first->prev);
		assert(l.m_head->next == first);
		assert(l.m_head->item == "Zero");
		assert(l.m_tail == second);

		break;
	}
	case 5: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = second;
		l.m_size = 2;

		l.insert(4, "third");

		//Examing the final state of our list after call
		assert(l.m_size == 3);
		assert(l.m_head == first);
		assert(l.m_tail->next == nullptr);
		assert(l.m_tail->item == "third");
		assert(l.m_tail->prev == second);
		break;
	}
	case 6: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = second;
		l.m_size = 2;

		l.insert(1, "half");

		//Examing the final state of our list after call
		assert(l.m_size == 3);
		assert(l.m_head == first);
		assert(l.m_head->prev == nullptr);
		assert(l.m_head->next->item == "half");
		assert(l.m_tail->prev == l.m_head->next);
		assert(l.m_tail == second);
		assert(l.m_tail->next == nullptr);
		assert(l.m_head->next->next == l.m_tail);
		assert(l.m_head == l.m_tail->prev->prev);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//Test find
int test_find(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<int> l;

		assert(l.find(100) == -1);

		break;
	}
	case 1: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		//Examing the final state of our list after call
		assert(l.find("Zero") == -1);
		assert(l.find("first") == 0);
		assert(l.find("second") == 1);
		assert(l.find("third") == 2);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//Test front
int test_front(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;

		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.front() == "first");
		break;
	}
	case 1: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.front() == "first");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//Test rear
int test_rear(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.rear() == "first");
		break;
	}
	case 1: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.rear() == "third");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}
//Test get
int test_get(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.get(0) == "first");
		break;
	}
	case 1: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.get(0) == "first");
		assert(l.get(1) == "second");
		assert(l.get(2) == "third");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//Test pop_front
int test_pop_front(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> l;
		assert(l.pop_front() == false);
		break;
	}
	case 1: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.pop_front() == true);
		assert(l.m_size == 0);
		assert(l.m_head == nullptr);
		assert(l.m_tail == nullptr);
		break;
	}
	case 2: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.pop_front() == true);
		assert(l.m_size == 2);
		assert(l.m_head == second);
		assert(l.m_tail == third);
		assert(l.m_head->prev == nullptr);
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}
//Test pop_rear
int test_pop_rear(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> l;
		assert(l.pop_rear() == false);
	}
	case 1: {//Test with empty list
		List<std::string>::Node* first = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.pop_rear() == true);
		assert(l.m_size == 0);
		assert(l.m_head == nullptr);
		assert(l.m_tail == nullptr);
		break;
	}
	case 2: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.pop_rear() == true);
		assert(l.m_size == 2);
		assert(l.m_head == first);
		assert(l.m_tail == second);
		assert(l.m_tail->next == nullptr);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}
int test_remove(int testNum) {
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> l;
		assert(l.remove(-1) == false);
	}
	case 1: {//Test with empty list
		List<int> l;
		assert(l.remove(9999) == false);
		break;
	}
	case 2: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.remove(-1) == false);

		break;
	}
	case 3: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.remove(9999) == false);

		break;
	}
	case 4: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = first;
		l.m_size = 1;

		assert(l.remove(0) == true);
		assert(l.m_size == 0);
		assert(l.m_head == nullptr);
		assert(l.m_tail == nullptr);
		break;
	}
	case 5: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.remove(0) == true);
		assert(l.m_size == 2);
		assert(l.m_head == second);
		assert(l.m_head->prev == nullptr);
		assert(l.m_tail == third);
		break;
	}
	case 6: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.remove(2) == true);
		assert(l.m_size == 2);
		assert(l.m_head == first);
		assert(l.m_tail->next == nullptr);
		assert(l.m_tail == second);
		break;
	}
	case 7: {
		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.remove(1) == true);
		assert(l.m_size == 2);

		assert(l.m_head == first);
		assert(l.m_tail == third);

		assert(l.m_head->next == third);
		assert(l.m_tail->prev == first);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}
//also come back to this
int test_print(int testNum) {
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		std::string test_string1("Tom Dick Mary\n"); //Without lagging space
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		List<std::string>::Node* first = debugnew List<std::string>::Node;
		List<std::string>::Node* second = debugnew List<std::string>::Node;
		List<std::string>::Node* third = debugnew List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = test_vector[0];
		first->prev = nullptr;
		first->next = second;

		second->item = test_vector[1];
		second->prev = first;
		second->next = third;

		third->item = test_vector[2];
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

		l.print();
		std::cout.rdbuf(old);

		std::string text = buffer.str();

		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length());
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}

		break;
	}
	case 1: {
		std::string test_string1(""); //Without lagging space
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//hijack cout buffer
		std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

		l.print();

		//restore cout buffer
		std::cout.rdbuf(old);

		std::string text = buffer.str();
		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length());
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}
int test_size(int testNum) {
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		assert(l.size() == 3);

		break;
	}
	case 1: {
		List<std::string> l;
		assert(l.size() == 0);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

int test_copyCtor(int testNum) {
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		List<int> l;
		List<int> p(l);

		//Set up the initial state of the list to test
		assert(p.m_head == nullptr);
		assert(p.m_tail == nullptr);
		assert(p.m_size == 0);

		break;
	}

	case 1: {
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		List<int> p(l);

		assert(p.m_head != nullptr);
		assert(p.m_tail != nullptr);
		assert(p.m_size == 3);

		assert(p.m_head->item == first->item);
		assert(p.m_head->next->item == second->item);
		assert(p.m_tail->prev->item == second->item);
		assert(p.m_tail->item == third->item);

		assert(p.m_head != first);
		assert(p.m_tail != third);

		break;
	}
	case 2: {
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		List<int> p(l);

		assert(p.m_head != nullptr);
		assert(p.m_tail != nullptr);
		assert(p.m_size == 3);

		assert(p.m_head->item == first->item);
		assert(p.m_head->next->item == second->item);
		assert(p.m_tail->prev->item == second->item);
		assert(p.m_tail->item == third->item);

		//check aliasing
		assert(p.m_head != first);
		assert(p.m_head != second);
		assert(p.m_head != third);

		assert(p.m_head->next != first);
		assert(p.m_head->next != second);
		assert(p.m_head->next != third);

		assert(p.m_tail != first);
		assert(p.m_tail != second);
		assert(p.m_tail != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

int test_assgnOper(int testNum) {
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		List<int> l;
		List<int> p;

		p = l;
		//Set up the initial state of the list to test

		assert(p.m_head == nullptr);
		assert(p.m_tail == nullptr);
		assert(p.m_size == 0);

		break;
	}

	case 1: {
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		List<int> p;

		p = l;

		assert(p.m_head != nullptr);
		assert(p.m_tail != nullptr);
		assert(p.m_size == 3);

		assert(p.m_head->item == first->item);
		assert(p.m_head->next->item == second->item);
		assert(p.m_tail->prev->item == second->item);
		assert(p.m_tail->item == third->item);

		assert(p.m_head != first);
		assert(p.m_tail != third);

		break;
	}

	case 2: {
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		List<int> p;

		p = l;

		assert(p.m_head != nullptr);
		assert(p.m_tail != nullptr);
		assert(p.m_size == 3);

		assert(p.m_head->item == first->item);
		assert(p.m_head->next->item == second->item);
		assert(p.m_tail->prev->item == second->item);
		assert(p.m_tail->item == third->item);

		//check aliasing
		assert(p.m_head != first);
		assert(p.m_head != second);
		assert(p.m_head != third);

		assert(p.m_head->next != first);
		assert(p.m_head->next != second);
		assert(p.m_head->next != third);

		assert(p.m_tail != first);
		assert(p.m_tail != second);
		assert(p.m_tail != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}
//come back to this aswell
int test_mem_destructor(int testNum) {
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		RESET();
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		{
			List<int> l;

			//Set up the initial state of the list to test
			l.m_head = first;
			l.m_tail = third;
			l.m_size = 3;
		} //destructor

		GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Destructor: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);

		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

int test_mem_assgnOper(int testNum) {
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		RESET();
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;

		List<int> p;
		l = p;
		//GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Assign Op: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);
		break;
	}
	case 1: {
		RESET();
		List<int>::Node* first = debugnew List<int>::Node;
		List<int>::Node* second = debugnew List<int>::Node;
		List<int>::Node* third = debugnew List<int>::Node;

		//Link together to make a valid linked list
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.m_head = first;
		l.m_tail = third;
		l.m_size = 3;
		//GETMEMORYREPORT();

		l = l;
		if (SIZE() != 3) {
			std::cerr << "Assign Op: Improper assignment" << std::endl;
		}
		assert(SIZE() == 3);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;
	}
	return 0;
}

//This is to show all the tests.  Do not run all at once, you will confuse any issues
//that occur with the wrong test.  It is often the case that when something comes up, it isn't
//specifically with what you believe is the "current" test but rather one that came before.
void runAllTests() {
	test_empty(0);
	test_empty(1);

	test_push_front(0);
	test_push_front(1);

	test_push_rear(0);
	test_push_rear(1);

	test_insert(0);
	test_insert(1);
	test_insert(2);
	test_insert(3);
	test_insert(4);
	test_insert(5);
	test_insert(6);

	test_find(0);
	test_find(1);

	test_front(0);
	test_front(1);

	test_rear(0);
	test_rear(1);

	test_get(0);
	test_get(1);

	test_pop_front(0);
	test_pop_front(1);
	test_pop_front(2);

	test_pop_rear(0);
	test_pop_rear(1);
	test_pop_rear(2);

	test_remove(0);
	test_remove(1);
	test_remove(2);
	test_remove(3);
	test_remove(4);
	test_remove(5);
	test_remove(6);
	test_remove(7);

	test_print(0);
	test_print(1);

	test_size(0);
	test_size(1);

	test_copyCtor(0);
	test_copyCtor(1);
	test_copyCtor(2);

	test_assgnOper(0);
	test_assgnOper(1);
	test_assgnOper(2);

	test_mem_destructor(0);
	test_mem_assgnOper(0);
	test_mem_assgnOper(1);
}

#endif
