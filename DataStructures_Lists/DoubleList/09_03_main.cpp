#include <iostream>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////            LIST        ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

struct Node
{
    int data = 0;
    Node *previousNode = nullptr;
    Node *nextNode = nullptr;
};

struct List
{
    Node *firstNode = nullptr, *lastNode = nullptr;

    ~List() { clear(); }

    void insert();
    void remove();
    void edit();
    void contains();
    void print();
    void clear();
    void iterate();
};

void List::insert()
{
    Node *newNode = new Node();

    std::cout << "Please enter a value for the new Nodee: ";
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

void List::remove()
{
    int fetchValue = 0;
    bool bFound = false;
    Node *currentNode = firstNode;

    std::cout << "Please enter a Nodee to fetch: ";
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

void List::edit()
{
    int fetchValue = 0;
    bool bFound = false;
    Node *currentNode = firstNode;

    std::cout << "Please enter a Nodee to fetch: ";
    std::cin >> fetchValue;
    if (firstNode != nullptr)
    {
        while (currentNode != nullptr && !bFound)
        {
            if (currentNode->data == fetchValue)
            {
                bFound = true;
                std::cout << "Enter a new value for the Nodee: ";
                std::cin >> currentNode->data;
                std::cout << "New Node value is " << currentNode->data << std::endl;
            }
            currentNode = currentNode->nextNode;
        }
        if (!bFound)
            std::cout << "Node with value " << fetchValue << " was never found" << std::endl;
    }
    else
        std::cout << "The list is empty" << std::endl;
}

void List::contains()
{
    int fetchValue = 0;
    bool bFound = false;
    Node *currentNode = firstNode;

    std::cout << "Please enter a Node to fetch: ";
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

void List::iterate()
{
    int option_iterate = 0;
    Node *it = firstNode;
    while (option_iterate != 3)
    {

        Node *currentNode = firstNode;
        if (firstNode != nullptr)
            while (currentNode != nullptr)
            {
                if (it == currentNode)
                    std::cout << currentNode->data << " <-" << std::endl;
                else
                    std::cout << currentNode->data << std::endl;
                currentNode = currentNode->nextNode;
            }
        else
        {
            std::cout << "The list is empty" << std::endl;
            break;
        }

        std::cout << "\nPlease enter 1 (next), 2 (previous) or 3 (menu): ";
        std::cin >> option_iterate;
        std::cout << std::endl;
        switch (option_iterate)
        {
        case 1:
            if (it != nullptr && it != lastNode)
                it = it->nextNode;
            break;
        case 2:
            if (it != nullptr && it != firstNode)
                it = it->previousNode;
            break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////            MAIN        ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

int main()
{
    List myList;
    int option_menu = 0;
    do
    {
        std::cout << "\n|------------------------------|";
        std::cout << "\n|       # SIMPLE LIST #        |";
        std::cout << "\n|------------------------------|";
        std::cout << "\n|  1.- Insert     5.- Print    |";
        std::cout << "\n|  2.- Remove     6.- Clear    |";
        std::cout << "\n|  3.- Edit       7.- Iterate  |";
        std::cout << "\n|  4.- Contains   8.- Exit     |";
        std::cout << "\n|------------------------------|" << std::endl;
        std::cout << "\nPlease choose an option: ";
        std::cin >> option_menu;
        switch (option_menu)
        {
        case 1:
            std::cout << "\nINSERT A NODE IN THE LIST\n"
                      << std::endl;
            myList.insert();
            break;
        case 2:
            std::cout << "\nREMOVE A NODE FROM THE LIST\n"
                      << std::endl;
            myList.remove();
            break;
        case 3:
            std::cout << "\nEDIT A NODE IN THE LIST\n"
                      << std::endl;
            myList.edit();
            break;
        case 4:
            std::cout << "\nCHECK IF A NODE IS IN THE LIST\n"
                      << std::endl;
            myList.contains();
            break;
        case 5:
            std::cout << "\nPRINT THE LIST\n"
                      << std::endl;
            myList.print();
            break;
        case 6:
            std::cout << "\nCLEAR THE LIST\n"
                      << std::endl;
            myList.clear();
            break;
        case 7:
            std::cout << "\nMANUALLY ITERATE THE LIST\n"
                      << std::endl;
            myList.iterate();
            break;
        case 8:
            std::cout << "\nEXIT THE PROGRAM\n"
                      << std::endl;
            myList.clear();
            break;
        default:
            std::cout << "\nInvalid option\n"
                      << std::endl;
            break;
        }
    } while (option_menu != 8);
    return 0;
}
