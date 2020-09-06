#ifndef LIST_H
#define LIST_H

#include <iostream>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////            LIST        ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

class List
{
    struct Node
    {
        int data = 0;
        Node *previousNode = nullptr;
        Node *nextNode = nullptr;
    };

public:
    ~List() { clear(); }

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
    Node *newNode = new Node();

    std::cout << "Please enter a value for the new Node: ";
    std::cin >> newNode->data;
    if (m_FirstNode == nullptr)
    {
        m_FirstNode = newNode;
        m_FirstNode->nextNode = m_FirstNode->previousNode = nullptr;
        m_LastNode = m_FirstNode;
    }
    else
    {
        m_LastNode->nextNode = newNode;
        newNode->nextNode = nullptr;
        newNode->previousNode = m_LastNode;
        m_LastNode = newNode;
    }
    std::cout << "Node created successfully" << std::endl;
}

void List::remove()
{
    int fetchValue = 0;
    bool bFound = false;
    Node *thisNode = m_FirstNode;

    std::cout << "Please enter a Nodee to fetch: ";
    std::cin >> fetchValue;
    if (m_FirstNode != nullptr)
    {
        while (thisNode != nullptr && !bFound)
        {
            if (thisNode->data == fetchValue)
            {
                if (thisNode == m_FirstNode)
                {
                    m_FirstNode = thisNode->nextNode;
                    if (m_FirstNode != nullptr)
                        m_FirstNode->previousNode = nullptr;
                }
                else if (thisNode == m_LastNode)
                {
                    thisNode->previousNode->nextNode = nullptr;
                    m_LastNode = thisNode->previousNode;
                }
                else
                {
                    thisNode->previousNode->nextNode = thisNode->nextNode;
                    thisNode->nextNode->previousNode = thisNode->previousNode;
                }
                delete thisNode;
                bFound = true;
                std::cout << "Node removed" << std::endl;
            }
            thisNode = thisNode->nextNode;
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
    Node *thisNode = m_FirstNode;

    std::cout << "Please enter a Nodee to fetch: ";
    std::cin >> fetchValue;
    if (m_FirstNode != nullptr)
    {
        while (thisNode != nullptr && !bFound)
        {
            if (thisNode->data == fetchValue)
            {
                bFound = true;
                std::cout << "Enter a new value for the Nodee: ";
                std::cin >> thisNode->data;
                std::cout << "New Node value is " << thisNode->data << std::endl;
            }
            thisNode = thisNode->nextNode;
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
    Node *thisNode = m_FirstNode;

    std::cout << "Please enter a Node to fetch: ";
    std::cin >> fetchValue;
    if (m_FirstNode != nullptr)
    {
        while (thisNode != nullptr && !bFound)
        {
            if (thisNode->data == fetchValue)
            {
                bFound = true;
                std::cout << "Node with value " << fetchValue << " was found!" << std::endl;
            }
            thisNode = thisNode->nextNode;
        }
        if (!bFound)
            std::cout << "Node with value " << fetchValue << " was never found" << std::endl;
    }
    else
        std::cout << "The list is empty" << std::endl;
}

void List::print()
{
    int direction = 0;
    Node *thisNode;

    while (direction != 1 && direction != 2)
    {
        std::cout << "Enter 1 to print first to last, enter 2 to print last to first: ";
        std::cin >> direction;
        std::cout << std::endl;
    }
    if (direction == 1)
    {
        thisNode = m_FirstNode;
        if (m_FirstNode != nullptr)
            while (thisNode != nullptr)
            {
                std::cout << thisNode->data << std::endl;
                thisNode = thisNode->nextNode;
            }
        else
            std::cout << "The list is empty" << std::endl;
    }
    if (direction == 2)
    {
        thisNode = m_LastNode;
        if (m_LastNode != nullptr)
            while (thisNode != nullptr)
            {
                std::cout << thisNode->data << std::endl;
                thisNode = thisNode->previousNode;
            }
        else
            std::cout << "The list is empty" << std::endl;
    }
}

void List::clear()
{
    Node *thisNode = m_FirstNode, *prevNode;
    int direction = 0;

    if (m_FirstNode != nullptr)
    {
        while (thisNode != nullptr)
        {
            prevNode = thisNode;
            thisNode = thisNode->nextNode;
            delete prevNode;
        }
        m_FirstNode = m_LastNode = nullptr;
    }
    else
        std::cout << "The list is empty" << std::endl;
}

void List::iterate()
{
    int option_iterate = 0;
    Node *it = m_FirstNode;
    while (option_iterate != 3)
    {
        Node *thisNode = m_FirstNode;
        if (m_FirstNode != nullptr)
            while (thisNode != nullptr)
            {
                if (it == thisNode)
                    std::cout << thisNode->data << " <-" << std::endl;
                else
                    std::cout << thisNode->data << std::endl;
                thisNode = thisNode->nextNode;
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
            if (it != nullptr && it != m_LastNode)
                it = it->nextNode;
            break;
        case 2:
            if (it != nullptr && it != m_FirstNode)
                it = it->previousNode;
            break;
        }
    }
}

#endif /* LIST_H */