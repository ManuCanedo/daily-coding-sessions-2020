#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

#define VALID_CHARACTERS "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"

struct Person
{
	std::string firstName{ "Unknown" };
	std::string otherNames{ "Mr. Smith" };
	std::string email{ "" };
	std::string telephone{ "" };
	std::map<std::string, std::string> address{};

	Person(std::string& firstName, std::string& otherNames, std::string& email, std::string& telephone, std::vector<std::string>&& address)
	{
		SetFirstName(firstName);
		SetOtherNames(otherNames);
		SetEmail(email);
		SetTelephone(telephone);
		SetAddress(address);
	}

	bool SetFirstName(const std::string& firstName)
	{
		if (ValidateName(firstName))
		{
			this->firstName = firstName;
			return true;
		}
		else
			return false;
	}

	bool SetOtherNames(const std::string& otherNames)
	{
		if (ValidateName(otherNames))
		{
			this->otherNames = otherNames;
			return true;
		}
		else
			return false;
	}

	bool SetEmail(const std::string& email)
	{
		if (ValidateEmail(email))
		{
			this->email = email;
			return true;
		}
		else
			return false;
	}

	bool SetTelephone(const std::string& telephone)
	{
		if (ValidateTelephone(telephone))
		{
			this->telephone = telephone;
			return true;
		}
		else
			return false;
	}

	bool SetAddress(const std::vector<std::string>& address)
	{
		if (ValidateName(address[0]))
			this->address["Street"] = address[0];
		else
			return false;
		if (ValidateName(address[1]))
			this->address["Town"] = address[1];
		else
			return false;
		if (ValidateName(address[2]))
			this->address["Country"] = address[2];
		else
			return false;

		return true;
	}

	static inline bool isChar(const char c)
	{
		return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
	}

	static inline bool isDigit(const char c)
	{
		return (c >= '0' && c <= '9');
	}

	static bool ValidateName(const std::string& name)
	{
		return name.find_first_not_of(VALID_CHARACTERS) == std::string::npos;
	}

	static bool ValidateEmail(const std::string& email)
	{
		if (!isChar(email[0])) return 0;

		int At = -1, Dot = -1;

		for (int i = 0; i < email.length(); i++) 
			if (email[i] == '@') 
				At = i;
			else if (email[i] == '.') 
				Dot = i;

		if (At == -1 || Dot == -1) return 0;
		if (At > Dot) return 0;

		return (Dot < (email.length() - 1));
	}

	static bool ValidateTelephone(const std::string& telephone)
	{
		return telephone.length() > 7 && telephone.length() < 10 && telephone.find_first_not_of("0123456789") == std::string::npos;
	}

	bool operator==(const Person& p) const
	{
		return firstName == p.firstName && otherNames == p.otherNames && email == p.email
			&& telephone == p.telephone && address.find("Street")->second == p.address.find("Street")->second
			&& address.find("Town")->second == p.address.find("Town")->second
			&& address.find("Country")->second == p.address.find("Country")->second;
	}

	bool operator!=(const Person& other) const
	{
		return !(*this == other);
	}

	friend std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		os << p.firstName << "*" << p.otherNames << "*" << p.email << "*" << p.telephone << "*" 
			<< p.address.find("Street")->second << "*" << p.address.find("Town")->second << "*" << p.address.find("Country")->second;
		return os;
	}
};
