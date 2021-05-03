#include <iostream>
#include "08_25_List.h"

////////////////////////////////////////////////////////////////////////////////////
////////////////////////            MAIN        ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

int main()
{
	List myList;
	int option_menu = 0;
	do {
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
		switch (option_menu) {
		case 1:
			std::cout << "\nINSERT A NODE IN THE LIST\n" << std::endl;
			myList.insert();
			break;
		case 2:
			std::cout << "\nREMOVE A NODE FROM THE LIST\n" << std::endl;
			myList.remove();
			break;
		case 3:
			std::cout << "\nEDIT A NODE IN THE LIST\n" << std::endl;
			myList.edit();
			break;
		case 4:
			std::cout << "\nCHECK IF A NODE IS IN THE LIST\n" << std::endl;
			myList.contains();
			break;
		case 5:
			std::cout << "\nPRINT THE LIST\n" << std::endl;
			myList.print();
			break;
		case 6:
			std::cout << "\nCLEAR THE LIST\n" << std::endl;
			myList.clear();
			break;
		case 7:
			std::cout << "\nMANUALLY ITERATE THE LIST\n" << std::endl;
			myList.iterate();
			break;
		case 8:
			std::cout << "\nEXIT THE PROGRAM\n" << std::endl;
			myList.clear();
			break;
		default:
			std::cout << "\nInvalid option\n" << std::endl;
			break;
		}
	} while (option_menu != 8);
	return 0;
}
