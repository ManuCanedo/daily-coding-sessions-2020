#include "Application.h"

#include <fstream>
#include <sstream>

void Application::Menu()
{
	int query = 0;

	Display([&query]() {
		std::cout << "\nADDRESS BOOK\n";
		std::cout << "\n";
		std::cout << "What do you want to do?\n";
		std::cout << "1.- Add\n";
		std::cout << "2.- Remove\n";
		std::cout << "3.- Search\n";
		std::cout << "4.- Exit\n" << std::endl;

		std::cout << "Option: ";
		std::cin >> query;
		});

	switch (query)
	{
	case 1:
		Add();
		break;
	case 2:
		Remove();
		break;
	case 3:
		Find();
		break;
	case 4:
		bExit = true;
		break;
	default:
		Display([]() { std::cout << "\nInvalid option!" << std::endl; });
		break;
	}
}

void Application::Add()
{
	std::string firstName, otherNames, email, telephone;
	std::string street, town, country;
	
	std::cin.get();
	do
	{
		Display([&]() {
			std::cout << "Enter a name: ";
			std::getline(std::cin, firstName);
			});
	} while (!Person::ValidateName(firstName));
	do
	{
		Display([&]() {
			std::cout << "Enter last/other names: ";
			std::getline(std::cin, otherNames);
			});
	} while (!Person::ValidateName(otherNames));
	do
	{
		Display([&]() {
			std::cout << "Enter an email: ";
			std::getline(std::cin, email);
			});
	} while (!Person::ValidateEmail(email));
	do
	{
		Display([&]() {
			std::cout << "Enter a telephone: ";
			std::getline(std::cin, telephone);
			});
	} while (!Person::ValidateTelephone(telephone));
	do
	{
		Display([&]() {
			std::cout << "Enter a street: ";
			std::getline(std::cin, street);
			});
	} while (!Person::ValidateName(street));
	do
	{
		Display([&]() {
			std::cout << "Enter a town: ";
			std::getline(std::cin, town);
			});
	} while (!Person::ValidateName(town));
	do
	{
		Display([&country]() {
			std::cout << "Enter a country: ";
			std::getline(std::cin, country);
			});
	} while (!Person::ValidateName(country));

	AddEntry({ firstName, otherNames, email, telephone, street, town, country });
}

void Application::Remove()
{
	Person* p = Find();

	if (p != nullptr)
	{
		RemoveEntry(*p);
		Display([]() { std::cout << "Entry has been removed!" << std::endl; });
	}
	else
		Display([]() { std::cout << "Unable to remove entry!" << std::endl; });
}

Person* Application::Find()
{
	int query = 0;
	std::string keyword;

	Display([&]() {
		std::cin.get();
		std::cout << "Enter the keyword: \n";
		std::getline(std::cin, keyword);

		std::cout << "\n";
		std::cout << "What search do you want to perform?\n";
		std::cout << "1.- Name\n";
		std::cout << "2.- Last Name\n";
		std::cout << "3.- Email\n";
		std::cout << "4.- Telephone\n";
		std::cout << "5.- Town\n";
		std::cout << "6.- Country\n";
		std::cout << "7.- Back to Menu\n" << std::endl;

		std::cout << "Option: ";
		std::cin >> query;
		});

	Person* p = nullptr;

	switch (query)
	{
	case 1:
		p = Search(DataType::NAME, keyword);
		break;
	case 2:
		p = Search(DataType::SURNAME, keyword);
		break;
	case 3:
		p = Search(DataType::EMAIL, keyword);
		break;
	case 4:
		p = Search(DataType::TELEPHONE, keyword);
		break;
	case 5:
		p = Search(DataType::TOWN, keyword);
		break;
	case 6:
		p = Search(DataType::COUNTRY, keyword);
		break;
	case 7:
		return p;
	default:
		Display([]() { std::cout << "\nNot a valid option!" << std::endl; });
		break;
	}

	if (p != nullptr)
		Display([]() { std::cout << "Entry has been found!" << std::endl; });
	else
		Display([]() { std::cout << "Entry has not been found!" << std::endl; });
	return p;
}


// Data Management

bool Application::AddEntry(const Person& p)
{
	data->push_back(p);
	for (auto& q : queries)
		search->find(q)->second.emplace(p.details.find(q)->second, &(data->back()));
	return true;
}

bool Application::RemoveEntry(const Person& p)
{
	for (auto& q : queries)
		search->find(q)->second.erase(p.details.find(q)->second);
	data->remove(p);
	return true;
}

Person* Application::Search(DataType q, const std::string& value)
{
	Person* p = nullptr;

	auto it = search->find(q);
	if (it != search->end())
	{
		auto itQueryMap = it->second.find(value);
		if (itQueryMap != it->second.end())
			p = itQueryMap->second;
	}
	return p;
}

void Application::LoadData()
{
	std::string line;
	std::ifstream file("save.txt");
	std::vector<std::string> fields(7);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			std::stringstream ss(line);
			for (auto& f : fields)
				std::getline(ss, f, '*');
			AddEntry({ fields[0], fields[1] , fields[2], fields[3], fields[4], fields[5], fields[6] });
		}
		file.close();
	}
}

void Application::SaveData()
{
	std::ofstream file("save.txt");
	std::copy(data->begin(), data->end(), std::ostream_iterator<Person>(file, "\n"));
}


// Entry Point

int main()
{
	Application app;
	app.Run();

	return 0;
}
