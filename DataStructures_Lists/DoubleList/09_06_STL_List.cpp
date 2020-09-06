#include <iostream>
#include <list>

void operateList(std::list<int> &myList, std::list<int>::iterator &it);

int main()
{
    int option_menu = 0;
    std::list<int> myList = {1, 2, 3, 4, 2, 9};
    std::list<int>::iterator selectIt = myList.begin();

    while (option_menu != 4)
    {
        for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
        {
            if (it == selectIt)
                std::cout << *it << " <-" << std::endl;
            else
                std::cout << *it << std::endl;
        }
        std::cout << "\n|-----------------------------------------------------------|";
        std::cout << "\n|   1.- Back     2.- Forward    3.- Select      4.- Exit    |";
        std::cout << "\n|-----------------------------------------------------------|:";
        std::cin >> option_menu;
        std::cout << std::endl;

        switch (option_menu)
        {
        case 2:
            if (selectIt != --myList.end())
                ++selectIt;
            break;
        case 1:
            if (selectIt != myList.begin())
                --selectIt;
            break;
        case 3:
            operateList(myList, selectIt);
            break;
        case 4:
            return 0;
        default:
            std::cout << "That is not an option!\n" << std::endl;
        }
    }
    std::cout << "\n" << std::endl;
    
    return 0;
}

inline void operateList(std::list<int> &myList, std::list<int>::iterator &it)
{
    int option_menu = 0;
    bool bLoop = true;
    while (bLoop)
    {
        bLoop = false;
        std::cout << "\n|------------------------------------------|";
        std::cout << "\n|   1.- Remove     2.- Add     3.- Back    |";
        std::cout << "\n|------------------------------------------|: ";
        std::cin >> option_menu;
        std::cout << std::endl;

        switch (option_menu)
        {
        case 1:
            it = myList.erase(it);
            if (it == myList.end())
                --it;
            break;
        case 2:
            int val;
            std::cout << "Please enter a value for the new ode: ";
            std::cin >> val;
            std::cout << std::endl;
            myList.insert(it, val);
            break;
        case 3:
            break;
        default:
            bLoop = true;
            std::cout << "That is not an option!\n" << std::endl;
        }
    }
}
