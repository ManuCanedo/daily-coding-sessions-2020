#ifndef LIST_H
#define LIST_H

#include <iostream>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////            LIST        ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

class List {
	struct Node {
		int data = 0;
		Node* nextNode = nullptr;
		Node* previousNode = nullptr;
	};

public:
	~List()
	{
		clear();
	}

	void insert();
	void remove();
	void edit();
	void contains();
	void print();
	void clear();
	void iterate();

private:
	Node *m_FirstNode = nullptr, *m_LastNode = nullptr;
};

void List::insert()
{
	Node* newNode = new Node();

	std::cout << "Please enter a value for the new Node: ";
	std::cin >> newNode->data;
	if (m_FirstNode == nullptr) {
		m_FirstNode = newNode;
		m_LastNode = newNode;
		m_FirstNode->nextNode = m_FirstNode;
		m_FirstNode->previousNode = m_LastNode;
	} else {
		m_LastNode->nextNode = newNode;
		newNode->previousNode = m_LastNode;
		newNode->nextNode = m_FirstNode;
		m_LastNode = newNode;
		m_FirstNode->previousNode = m_LastNode;
	}
	std::cout << "Node created successfully" << std::endl;
}

void List::remove()
{
	int fetchValue = 0;
	bool bFound = false;
	Node* thisNode = m_FirstNode;
	Node* prevNode = nullptr;

	std::cout << "Please enter a Node to fetch: ";
	std::cin >> fetchValue;
	if (m_FirstNode != nullptr) {
		do {
			if (thisNode->data == fetchValue) {
				if (thisNode == m_FirstNode) {
					if (m_FirstNode != m_FirstNode->nextNode) {
						m_FirstNode = m_FirstNode->nextNode;
						m_FirstNode->previousNode = m_LastNode;
						m_LastNode->nextNode = m_FirstNode;
					} else
						m_FirstNode = m_LastNode = nullptr;
				} else if (thisNode == m_LastNode) {
					m_LastNode = prevNode;
					m_LastNode->nextNode = m_FirstNode;
					m_FirstNode->nextNode = m_LastNode;
				} else {
					prevNode->nextNode = thisNode->nextNode;
					thisNode->nextNode->previousNode = prevNode;
				}
				delete thisNode;
				bFound = true;
				std::cout << "Node removed" << std::endl;
			}
			prevNode = thisNode;
			thisNode = thisNode->nextNode;
		} while (thisNode != m_FirstNode && !bFound);
		if (!bFound)
			std::cout << "Node with value " << fetchValue << " was never found"
				  << std::endl;
	} else
		std::cout << "The list is empty" << std::endl;
}

void List::edit()
{
	int fetchValue = 0;
	bool bFound = false;
	Node* thisNode = m_FirstNode;

	std::cout << "Please enter a Node to fetch: ";
	std::cin >> fetchValue;
	if (m_FirstNode != nullptr) {
		do {
			if (thisNode->data == fetchValue) {
				bFound = true;
				std::cout << "Enter a new value for the Node: ";
				std::cin >> thisNode->data;
				std::cout << "New Node value is " << thisNode->data << std::endl;
			}
			thisNode = thisNode->nextNode;
		} while (thisNode != m_FirstNode && !bFound);
		if (!bFound)
			std::cout << "Node with value " << fetchValue << " was never found"
				  << std::endl;
	} else
		std::cout << "The list is empty" << std::endl;
}

void List::contains()
{
	int fetchValue = 0;
	bool bFound = false;
	Node* thisNode = m_FirstNode;

	std::cout << "Please enter a Node to fetch: ";
	std::cin >> fetchValue;
	if (m_FirstNode != nullptr) {
		do {
			if (thisNode->data == fetchValue) {
				bFound = true;
				std::cout << "Node with value " << fetchValue << " was found!"
					  << std::endl;
			}
			thisNode = thisNode->nextNode;
		} while (thisNode != m_FirstNode && !bFound);
		if (!bFound)
			std::cout << "Node with value " << fetchValue << " was never found"
				  << std::endl;
	} else
		std::cout << "The list is empty" << std::endl;
}

void List::print()
{
	int direction = 0;
	Node* thisNode;

	while (direction != 1 && direction != 2) {
		std::cout << "Enter 1 to print first to last, enter 2 to print last to first: ";
		std::cin >> direction;
		std::cout << std::endl;
	}
	if (direction == 1) {
		thisNode = m_FirstNode;
		if (m_FirstNode != nullptr)
			do {
				std::cout << thisNode->data << std::endl;
				thisNode = thisNode->nextNode;
			} while (thisNode != m_FirstNode);
		else
			std::cout << "The list is empty" << std::endl;
	}
	if (direction == 2) {
		thisNode = m_LastNode;
		if (m_LastNode != nullptr)
			do {
				std::cout << thisNode->data << std::endl;
				thisNode = thisNode->previousNode;
			} while (thisNode != m_LastNode);
		else
			std::cout << "The list is empty" << std::endl;
	}
}

void List::clear()
{
	Node *thisNode = m_FirstNode, *prevNode;

	if (m_FirstNode != nullptr) {
		do {
			prevNode = thisNode;
			thisNode = thisNode->nextNode;
			delete prevNode;
		} while (thisNode != m_FirstNode);
		m_FirstNode = m_LastNode = nullptr;
	} else
		std::cout << "The list is empty" << std::endl;
}

void List::iterate()
{
	int option_iterate = 0;
	Node *it = m_FirstNode, *thisNode;
	while (option_iterate != 3) {
		thisNode = m_FirstNode;
		if (m_FirstNode != nullptr) {
			do {
				if (it == thisNode)
					std::cout << thisNode->data << " <-" << std::endl;
				else
					std::cout << thisNode->data << std::endl;
				thisNode = thisNode->nextNode;
			} while (thisNode != m_FirstNode);
		} else {
			std::cout << "The list is empty" << std::endl;
			break;
		}

		std::cout << "\nPlease enter 1 (next), 2 (previous) or 3 (menu): ";
		std::cin >> option_iterate;
		std::cout << std::endl;
		switch (option_iterate) {
		case 1:
			if (it != nullptr)
				it = it->nextNode;
			break;
		case 2:
			if (it != nullptr)
				it = it->previousNode;
			break;
		}
	}
}

#endif /* LIST_H */