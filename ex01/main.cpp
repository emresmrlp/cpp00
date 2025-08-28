/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:19:46 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/28 10:32:44 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <unistd.h>

static bool	getInputValue(std::string message, std::string &value)
{
	std::cout << message;
	std::getline(std::cin, value);
	if (std::cin.eof())
	{
		std::cout << "\n* End of file detected, exiting PhoneBook..." << std::endl;
		return false;
	}
	if (value.empty())
	{
		std::cout << "* Invalid input. Please try again." << std::endl;
		return getInputValue(message, value);
	}
	return true;
}

bool	addContact(PhoneBook &phoneBook)
{
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

	if (!getInputValue("Enter first name: ", FirstName))
		return false;
	if (!getInputValue("Enter last name: ", LastName))
		return false;
	if (!getInputValue("Enter Nickname: ", Nickname))
		return false;
	if (!getInputValue("Enter phone number: ", PhoneNumber))
		return false;
	if (!getInputValue("Enter darkest secret: ", DarkestSecret))
		return false;
	phoneBook.addContact(FirstName, LastName, Nickname, PhoneNumber,
		DarkestSecret);
	std::cout << "Contact added successfully!" << std::endl;
	return true;
}

bool	searchContact(PhoneBook &phoneBook)
{
	std::string index;
	
	phoneBook.listContact();
	std::cout << "Please enter the index of the contact (0 to exit):"
		<< std::endl;
	while (1)
	{
		std::cout << "-> ";
		if (!std::getline(std::cin, index))
		{
			if (std::cin.eof())
			{
				std::cout << "\n* End of file detected, exiting PhoneBook..." << std::endl;
				return false;
			}
		}
		if (index == "0")
		{
			std::cout << "Exiting search..." << std::endl;
			return true;
		}
		else if (index.length() != 1 || index[0] < '1' || index[0] > '8')
		{
			std::cout << "* Invalid index! (1-8 only)" << std::endl;
			std::cout << "* Enter index (0) to exit." << std::endl;
		}
		else if (index[0] - '0' <= phoneBook.getNumContacts())
		{
			phoneBook.getContactInfo(index[0] - '0');
			return true;
		}
		else
			std::cout << "* Index not found!" << std::endl;
	}
	return true;
}

void openPhoneBook(PhoneBook phoneBook, std::string command)
{
	std::cout << "You opened the PhoneBook! (by ysumeral)" << std::endl;
	std::cout << "Please select a command (ADD, SEARCH, EXIT):"
		<< std::endl;
	while (1)
	{
		std::cout << "-> ";
		if (!std::getline(std::cin, command))
		{
			if (std::cin.eof())
			{
				std::cout << "\n* End of file detected, exiting PhoneBook..."
					<< std::endl;
				break ;
			}	
		}
		if (command == "ADD")
		{
			if (!addContact(phoneBook))
				break;
		}
		else if (command == "SEARCH")
		{
			if (!searchContact(phoneBook))
				break;
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting PhoneBook... Goodbye!" << std::endl;
			break ;
		}
		else
		{
			std::cout << "* Invalid command!" << std::endl;
			std::cout << "* I said (ADD, SEARCH, EXIT) >:(" << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	PhoneBook	phoneBook;
	std::string	command;

	(void)argc;
	(void)argv;
	command = "";
	openPhoneBook(phoneBook, command);
	return (0);
}
