#pragma once

#include <string_view>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define VALID_CHARACTERS "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// enum class DATATYPE lists all the type of fields in a data entry
enum class DataType { NAME, SURNAME, EMAIL, TELEPHONE, STREET, TOWN, COUNTRY };

// array QUERIES lists all the types of searchs
constexpr DataType queries[]{ DataType::NAME,	   DataType::SURNAME, DataType::EMAIL,
			      DataType::TELEPHONE, DataType::TOWN,    DataType::COUNTRY };

struct Person {
	std::map<DataType, std::string> details;

	Person(std::string_view firstName, std::string_view otherNames, std::string_view email,
	       std::string_view telephone, std::string_view street, std::string_view town,
	       std::string_view country)
		: details({})
	{
		SetFirstName(firstName);
		SetOtherNames(otherNames);
		SetEmail(email);
		SetTelephone(telephone);
		SetStreet(street);
		SetTown(town);
		SetCountry(country);
	}

	// Data setters
	bool SetFirstName(std::string_view firstName)
	{
		if (ValidateName(firstName)) {
			details.emplace(DataType::NAME, firstName);
			return true;
		} else
			return false;
	}

	bool SetOtherNames(std::string_view otherNames)
	{
		if (ValidateName(otherNames)) {
			details.emplace(DataType::SURNAME, otherNames);
			return true;
		} else
			return false;
	}

	bool SetEmail(std::string_view email)
	{
		if (ValidateEmail(email)) {
			details.emplace(DataType::EMAIL, email);
			return true;
		} else
			return false;
	}

	bool SetTelephone(std::string_view telephone)
	{
		if (ValidateTelephone(telephone)) {
			details.emplace(DataType::TELEPHONE, telephone);
			return true;
		} else
			return false;
	}

	bool SetStreet(std::string_view street)
	{
		if (ValidateName(street)) {
			details.emplace(DataType::STREET, street);
			return true;
		} else
			return false;
	}

	bool SetTown(std::string_view town)
	{
		if (ValidateName(town)) {
			details.emplace(DataType::TOWN, town);
			return true;
		} else
			return false;
	}

	bool SetCountry(std::string_view country)
	{
		if (ValidateName(country)) {
			details.emplace(DataType::COUNTRY, country);
			return true;
		} else
			return false;
	}

	// Validate methods
	static bool ValidateName(std::string_view name)
	{
		return name.find_first_not_of(VALID_CHARACTERS) == std::string::npos;
	}

	static bool ValidateEmail(std::string_view email)
	{
		if (!isChar(email[0]))
			return 0;

		int At = -1, Dot = -1;

		for (int i = 0; i < email.length(); i++)
			if (email[i] == '@')
				At = i;
			else if (email[i] == '.')
				Dot = i;

		if (At == -1 || Dot == -1)
			return 0;
		if (At > Dot)
			return 0;

		return (Dot < (email.length() - 1));
	}

	static inline bool isChar(const char c)
	{
		return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
	}

	static inline bool isDigit(const char c)
	{
		return (c >= '0' && c <= '9');
	}

	static bool ValidateTelephone(std::string_view telephone)
	{
		return telephone.length() > 7 && telephone.length() < 10 &&
		       telephone.find_first_not_of("0123456789") == std::string::npos;
	}

	// Operators
	bool operator==(const Person& p) const
	{
		bool bEquals = true;
		for (auto& q : queries) {
			bEquals = details.find(q)->second == p.details.find(q)->second;
			if (!bEquals)
				break;
		}
		return bEquals;
	}

	bool operator!=(const Person& other) const
	{
		return !(*this == other);
	}

	friend std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		for (auto& q : queries)
			os << p.details.find(q)->second << "*";
		return os;
	}
};
