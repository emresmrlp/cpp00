/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:19:46 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/24 09:25:46 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <unistd.h>

static std::string	getInputValue(std::string message, std::string value)
{
	std::cout << message;
	std::getline(std::cin, value);
	if (std::cin.eof())
		exit(0);
	if (value.empty())
	{
		std::cout << "* Invalid input. Please try again." << std::endl;
		return getInputValue(message, value);
	}
	return (value);
}

void	addContact(PhoneBook &phoneBook)
{
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

	FirstName = getInputValue("Enter first name: ", FirstName);
	LastName = getInputValue("Enter last name: ", LastName);
	Nickname = getInputValue("Enter Nickname: ", Nickname);
	PhoneNumber = getInputValue("Enter phone number: ", PhoneNumber);
	DarkestSecret = getInputValue("Enter darkest secret: ", DarkestSecret);
	phoneBook.addContact(FirstName, LastName, Nickname, PhoneNumber,
		DarkestSecret);
	std::cout << "Contact added successfully!" << std::endl;
}

void	searchContact(PhoneBook &phoneBook)
{
	std::string index;
	
	phoneBook.listContact();
	std::cout << "Please enter the index of the contact (0 to exit):"
		<< std::endl;
	while (std::getline(std::cin, index))
	{
		std::cout << "-> ";
		if (std::cin.eof())
			return ;
		if (index == "0")
		{
			std::cout << "Exiting search..." << std::endl;
			return ;
		}
		else if (index.length() != 1 || index[0] < '1' || index[0] > '8')
		{
			std::cout << "* Invalid index! (1-8 only)" << std::endl;
			std::cout << "* Enter index (0) to exit." << std::endl;
		}
		else if (index[0] - '0' <= phoneBook.getNumContacts())
		{
			phoneBook.getContactInfo(index[0] - '0');
			return ;
		}
		else
			std::cout << "* Index not found!" << std::endl;
	}
	
}

void openPhoneBook(PhoneBook phoneBook, std::string command)
{
	std::cout << "You opened the PhoneBook!" << std::endl;
	std::cout << "Please select a command (ADD, SEARCH, EXIT):"
		<< std::endl;
	std::cout << "-> ";
	while (std::getline(std::cin, command))
	{
		std::cout << "-> ";
		if (command == "ADD")
			addContact(phoneBook);
		else if (command == "SEARCH")
			searchContact(phoneBook);
		else if (command == "EXIT")
		{
			std::cout << "Closing PhoneBook... Goodbye!" << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
			std::cout << "I said (ADD, SEARCH, EXIT) >:(" << std::endl;
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
