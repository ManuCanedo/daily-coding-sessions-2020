#pragma once

#include "DataEntry.h"

#include <unordered_map>
#include <functional>
#include <memory>
#include <list>

using QueryMap = typename std::unordered_multimap <std::string, Person*>;

class Application
{
public:
	Application()
		: data(std::make_unique<std::list<Person>>()),
		search(std::make_unique<std::map<DataType, QueryMap>>())
	{
		for (auto& q : queries)
			search->insert({ q, {} });
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

	void LoadData();
	void SaveData();
	bool AddEntry(const Person& p);
	bool RemoveEntry(const Person& p);
	Person* Search(DataType query, const std::string& value);

private:
	bool bExit{ false };
	std::unique_ptr<std::list<Person>> data;
	std::unique_ptr<std::map<DataType, QueryMap>> search;
};

