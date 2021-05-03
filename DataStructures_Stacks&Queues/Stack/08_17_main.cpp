////////// DATA STRUCTURES PRACTICE

// BUILDING A STACK

#include <iostream>

struct node {
	int data;
	node* nextNode;
} * firstNode;

void insertNode();
void removeNode();
void printStack();
void fetchNode();
void editNode();

int main()
{
	int option_menu = 0;
	do {
		std::cout << "\n|------------------------------|";
		std::cout << "\n|          # STACK #           |";
		std::cout << "\n|------------------------------|";
		std::cout << "\n|  1.- Insert      2.- Remove  |";
		std::cout << "\n|  3.- Fetch       4.- Print   |";
		std::cout << "\n|  5.- Edit        6.- Exit    |";
		std::cout << "\n|------------------------------|" << std::endl;
		std::cout << "\nPlease choose an option: ";
		std::cin >> option_menu;
		switch (option_menu) {
		case 1:
			std::cout << "\nINSERT NODE IN THE STACK\n" << std::endl;
			insertNode();
			break;
		case 2:
			std::cout << "\nREMOVE NODE FROM THE STACK\n" << std::endl;
			removeNode();
			break;
		case 3:
			std::cout << "\nFETCH NODE IN THE STACK\n" << std::endl;
			fetchNode();
			break;
		case 4:
			std::cout << "\nPRINT THE STACK CONTENT\n" << std::endl;
			printStack();
			break;
		case 5:
			std::cout << "\nEDIT A NODE IN THE STACK\n" << std::endl;
			editNode();
			break;
		case 6:
			std::cout << "\nEXIT THE PROGRAM\n" << std::endl;
			break;
		default:
			std::cout << "\nInvalid option\n" << std::endl;
			break;
		}
	} while (option_menu != 6);
	return 0;
}

// Creates a new Node element and adds it to the stack
void insertNode()
{
	node* newNode = new node();

	std::cout << "Please enter a value for the new node: ";
	std::cin >> newNode->data;
	newNode->nextNode = firstNode;
	firstNode = newNode;
	std::cout << "Node created successfully" << std::endl;
}

// Removes a given node from the stack
void removeNode()
{
	int fetchValue = 0;
	bool bFound = false;
	node* currentNode = firstNode;
	node* previousNode = nullptr;

	std::cout << "Please enter a node to remove: ";
	std::cin >> fetchValue;
	if (firstNode != nullptr) {
		while (currentNode != nullptr && !bFound) {
			if (currentNode->data == fetchValue) {
				if (currentNode == firstNode)
					firstNode = currentNode->nextNode;
				else
					previousNode->nextNode = currentNode->nextNode;

				delete currentNode;
				bFound = true;
				std::cout << "Node removed" << std::endl;
			}
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}
		if (!bFound)
			std::cout << "Node with value " << fetchValue << " was never found"
				  << std::endl;
	} else
		std::cout << "The stack is empty" << std::endl;
}

// Iterates through the stack retrieving each node data
void printStack()
{
	node* currentNode = firstNode;
	if (firstNode != nullptr) {
		while (currentNode != nullptr) {
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->nextNode;
		}
	} else
		std::cout << "The stack is empty" << std::endl;
}

// Looks for a value in the stack
void fetchNode()
{
	int fetchValue = 0;
	bool bFound = false;
	node* currentNode = firstNode;

	std::cout << "Please enter a node to fetch: ";
	std::cin >> fetchValue;
	if (firstNode != nullptr) {
		while (currentNode != nullptr && !bFound) {
			if (currentNode->data == fetchValue) {
				bFound = true;
				std::cout << "Node with value " << fetchValue << " was found!"
					  << std::endl;
			}
			currentNode = currentNode->nextNode;
		}
		if (!bFound)
			std::cout << "Node with value " << fetchValue << " was never found"
				  << std::endl;
	} else
		std::cout << "The stack is empty" << std::endl;
}

// Modifies the value of a given node
void editNode()
{
	int fetchValue = 0;
	bool bFound = false;
	node* currentNode = firstNode;

	std::cout << "Please enter a node to fetch: ";
	std::cin >> fetchValue;
	if (firstNode != nullptr) {
		while (currentNode != nullptr && !bFound) {
			if (currentNode->data == fetchValue) {
				bFound = true;
				std::cout << "Enter a new value for the node: ";
				std::cin >> currentNode->data;
				std::cout << "New node value is " << currentNode->data << std::endl;
			}
			currentNode = currentNode->nextNode;
		}
		if (!bFound)
			std::cout << "Node with value " << fetchValue << " was never found"
				  << std::endl;
	} else
		std::cout << "The stack is empty" << std::endl;
}
