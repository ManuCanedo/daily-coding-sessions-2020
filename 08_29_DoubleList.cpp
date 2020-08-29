#include <iostream>

struct node
{
    int data;
    node* previousNode = nullptr; 
    node* nextNode = nullptr;
} *firstNode, *lastNode;

void insertNode();
void removeNode();
void printList();
void fetchNode();
void editNode();

int main()
{
    int option_menu = 0;
    do
    {
        std::cout << "\n|------------------------------|";
        std::cout << "\n|       # DOUBLE LIST #        |";
        std::cout << "\n|------------------------------|";
        std::cout << "\n|  1.- Insert      2.- Remove  |";
        std::cout << "\n|  3.- Fetch       4.- Print   |";
        std::cout << "\n|  5.- Edit        6.- Exit    |";
        std::cout << "\n|------------------------------|" << std::endl;
        std::cout << "\nPlease choose an option: ";
        std::cin >> option_menu;
        switch (option_menu)
        {
        case 1:
            std::cout << "\nINSERT NODE IN THE LIST\n"
                      << std::endl;
            insertNode();
            break;
        case 2:
            std::cout << "\nREMOVE NODE FROM THE LIST\n"
                      << std::endl;
            removeNode();
            break;
        case 3:
            std::cout << "\nFETCH NODE IN THE LIST\n"
                      << std::endl;
            fetchNode();
            break;
        case 4:
            std::cout << "\nPRINT THE LIST CONTENT\n"
                      << std::endl;
            printList();
            break;
        case 5:
            std::cout << "\nEDIT A NODE IN THE LIST\n"
                      << std::endl;
            editNode();
            break;
        case 6:
            std::cout << "\nEXIT THE PROGRAM\n"
                      << std::endl;
            break;
        default:
            std::cout << "\nInvalid option\n"
                      << std::endl;
            break;
        }
    } while (option_menu != 6);
    return 0;
}

void insertNode()
{
    node *newNode = new node();

    std::cout << "Please enter a value for the new node: ";
    std::cin >> newNode->data;
    if (firstNode == nullptr)
    {
        firstNode = newNode;
        firstNode->nextNode = firstNode->previousNode = nullptr;
        lastNode = firstNode;
    }
    else
    {
        lastNode->nextNode = newNode;
        newNode->nextNode = nullptr;
        newNode->previousNode = lastNode;
        lastNode = newNode;
    }
    std::cout << "Node created successfully" << std::endl;
}

void printList()
{
    node *currentNode;
    int direction = 0;

    while (direction != 1 && direction != 2)
    {
        std::cout << "Enter 1 to print first to last, enter 2 to print last to first: ";
        std::cin >> direction;
    }
    if (direction == 1)
    {
        currentNode = firstNode;
        if (firstNode != nullptr)
            while (currentNode != nullptr)
            {
                std::cout << currentNode->data << std::endl;
                currentNode = currentNode->nextNode;
            }
        else
            std::cout << "The list is empty" << std::endl;
    }
    if (direction == 2)
    {
        currentNode = lastNode;
        if (lastNode != nullptr)
            while (currentNode != nullptr)
            {
                std::cout << currentNode->data << std::endl;
                currentNode = currentNode->previousNode;
            }
        else
            std::cout << "The list is empty" << std::endl;
    }
}

void fetchNode()
{
    int fetchValue = 0;
    bool bFound = false;
    node *currentNode = firstNode;

    std::cout << "Please enter a node to fetch: ";
    std::cin >> fetchValue;
    if (firstNode != nullptr)
    {
        while (currentNode != nullptr && !bFound)
        {
            if (currentNode->data == fetchValue)
            {
                bFound = true;
                std::cout << "Node with value " << fetchValue << " was found!" << std::endl;
            }
            currentNode = currentNode->nextNode;
        }
        if (!bFound)
            std::cout << "Node with value " << fetchValue << " was never found" << std::endl;
    }
    else
        std::cout << "The list is empty" << std::endl;
}

void editNode()
{
    int fetchValue = 0;
    bool bFound = false;
    node *currentNode = firstNode;

    std::cout << "Please enter a node to fetch: ";
    std::cin >> fetchValue;
    if (firstNode != nullptr)
    {
        while (currentNode != nullptr && !bFound)
        {
            if (currentNode->data == fetchValue)
            {
                bFound = true;
                std::cout << "Enter a new value for the node: ";
                std::cin >> currentNode->data;
                std::cout << "New node value is " << currentNode->data << std::endl;
            }
            currentNode = currentNode->nextNode;
        }
        if (!bFound)
            std::cout << "Node with value " << fetchValue << " was never found" << std::endl;
    }
    else
        std::cout << "The list is empty" << std::endl;
}

void removeNode()
{
    int fetchValue = 0;
    bool bFound = false;
    node *currentNode = firstNode;

    std::cout << "Please enter a node to fetch: ";
    std::cin >> fetchValue;
    if (firstNode != nullptr)
    {
        while (currentNode != nullptr && !bFound)
        {
            if (currentNode->data == fetchValue)
            {
                if (currentNode == firstNode)
                {
                    firstNode = currentNode->nextNode;
                    if (firstNode != nullptr)
                        firstNode->previousNode = nullptr;
                }
                else if (currentNode == lastNode)
                {
                    currentNode->previousNode->nextNode = nullptr;
                    lastNode = currentNode->previousNode;
                }
                else
                {
                    currentNode->previousNode->nextNode = currentNode->nextNode;
                    currentNode->nextNode->previousNode = currentNode->previousNode;
                }
                delete currentNode;
                bFound = true;
                std::cout << "Node removed" << std::endl;
            }
            currentNode = currentNode->nextNode;
        }
        if (!bFound)
            std::cout << "Node with value " << fetchValue << " was never found" << std::endl;
    }
    else
        std::cout << "The list is empty" << std::endl;
}