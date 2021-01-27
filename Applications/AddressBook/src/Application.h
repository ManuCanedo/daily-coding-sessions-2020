#pragma once

#include "DataEntry.h"

#include <memory>
#include <list>
#include <functional>
#include <unordered_map>

enum class QueryType
{
	NAME, SURNAME, EMAIL, TELEPHONE, TOWN, COUNTRY
};

using QueryMap = typename std::unordered_multimap <std::string, Person*>;

class Application
{

public:
	Application()
		: data(std::make_unique<std::list<Person>>()), 
		name(std::make_unique<QueryMap>()), surname(std::make_unique<QueryMap>()), email(std::make_unique<QueryMap>()), 
		telephone(std::make_unique<QueryMap>()), town(std::make_unique<QueryMap>()), country(std::make_unique<QueryMap>())
	{
		LoadData();
	}

	~Application()
	{
		SaveData();
	}

	void Run()
	{
		while (!bExit)
			Menu();
	}

	void Display(std::function<void()> func) 
	{ 
		func(); 
	}

private:
	void Menu();
	void Add();
	void Remove();
	Person* Find();

// Database Management
	void LoadData();
	void SaveData();
	bool AddEntry(const Person& p);
	bool RemoveEntry(const Person& p);
	Person* Search(QueryType query, const std::string& value);

private:
	bool bExit{ false };
	std::unique_ptr<std::list<Person>> data{ std::make_unique<std::list<Person>>() };

	std::unique_ptr<QueryMap> name{ std::make_unique<QueryMap>() };
	std::unique_ptr<QueryMap> surname{ std::make_unique<QueryMap>() };
	std::unique_ptr<QueryMap> email{ std::make_unique<QueryMap>() };
	std::unique_ptr<QueryMap> telephone{ std::make_unique<QueryMap>() };
	std::unique_ptr<QueryMap> town{ std::make_unique<QueryMap>() };
	std::unique_ptr<QueryMap> country{ std::make_unique<QueryMap>() };
};

