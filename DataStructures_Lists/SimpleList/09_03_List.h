#ifndef LIST_H
#define LIST_H

#include <iostream>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////            LIST        ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

struct Node
{
    int data = 0;
    Node *nextNode = nullptr;
};

class List
{
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

    std::cout << "Please enter a value for the new node: ";
    std::cin >> newNode->data;
    if (m_FirstNode == nullptr)
    {
        m_FirstNode = newNode;
        m_FirstNode->nextNode = nullptr;
        m_LastNode = m_FirstNode;
    }
    else
    {
        m_LastNode->nextNode = newNode;
        newNode->nextNode = nullptr;
        m_LastNode = newNode;
    }
    std::cout << "Node created successfully" << std::endl;
}

void List::remove()
{
    int fetchValue = 0;
    bool bFound = false;
    Node *thisNode = m_FirstNode;
    Node *prevNode = nullptr;

    std::cout << "Please enter a node to fetch: ";
    std::cin >> fetchValue;
    if (m_FirstNode != nullptr)
    {
        while (thisNode != nullptr && !bFound)
        {
            if (thisNode->data == fetchValue)
            {
                if (thisNode == m_FirstNode)
                    m_FirstNode = m_FirstNode->nextNode;
                else if (thisNode == m_LastNode)
                {
                    prevNode->nextNode = nullptr;
                    m_LastNode = prevNode;
                }
                else
                    prevNode->nextNode = thisNode->nextNode;
                delete thisNode;
                bFound = true;
                std::cout << "Node removed" << std::endl;
            }
            prevNode = thisNode;
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

    std::cout << "Please enter a node to fetch: ";
    std::cin >> fetchValue;
    if (m_FirstNode != nullptr)
    {
        while (thisNode != nullptr && !bFound)
        {
            if (thisNode->data == fetchValue)
            {
                bFound = true;
                std::cout << "Enter a new value for the node: ";
                std::cin >> thisNode->data;
                std::cout << "New node value is " << thisNode->data << std::endl;
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

    std::cout << "Please enter a node to fetch: ";
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
    Node *thisNode = m_FirstNode;
    if (m_FirstNode != nullptr)
        while (thisNode != nullptr)
        {
            std::cout << thisNode->data << std::endl;
            thisNode = thisNode->nextNode;
        }
    else
        std::cout << "The list is empty" << std::endl;
}

void List::clear()
{
    Node *thisNode = m_FirstNode;
    Node *prevNode = nullptr;
    if (m_FirstNode != nullptr)
    {
        while (thisNode != nullptr)
        {
            prevNode = thisNode;
            thisNode = thisNode->nextNode;
            delete prevNode;
        }
        m_FirstNode = nullptr;
    }
    else
        std::cout << "The list is clear" << std::endl;
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

        std::cout << "\nPlease enter 1 (next), 2 (beginning) or 3 (menu): ";
        std::cin >> option_iterate;
        std::cout << std::endl;
        switch (option_iterate)
        {
        case 1:
            if (it != nullptr && it != m_LastNode)
                it = it->nextNode;
            break;
        case 2:
            it = m_FirstNode;
            break;
        }
    }
}

#endif      /* LIST_H */