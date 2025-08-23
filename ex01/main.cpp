/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:19:46 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/23 19:33:26 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <unistd.h>

void	addContact(PhoneBook &phoneBook)
{
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, FirstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, LastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, Nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, PhoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, DarkestSecret);
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
	while (1)
	{
		std::cout << "-> ";
		std::getline(std::cin, index);
		if (index == "0")
		{
			std::cout << "Exiting search..." << std::endl;
			return ;
		}
		else if (index.length() != 1 || index[0] < '1' || index[0] > '8')
		{
			std::cout << "Invalid index! (1-8 only)" << std::endl;
			std::cout << "Enter index (0) to exit." << std::endl;
		}
		else if (index[0] - '0' <= phoneBook.getNumContacts())
		{
			phoneBook.getContactInfo(index[0] - '0');
			return ;
		}
		else
			std::cout << "Index not found!" << std::endl;
	}
	
}

void openPhoneBook(PhoneBook phoneBook, std::string command)
{
	std::cout << "You opened the PhoneBook!" << std::endl;
	std::cout << "Please select a command (ADD, SEARCH, EXIT):"
		<< std::endl;
	while (1)
	{
		std::cout << "-> ";
		std::getline(std::cin, command);
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

	(void)argv;
	if (argc != 1)
	{
		std::cout << "Error: Arguments not accepted." << std::endl;
		return (1);
	}
	command = "";
	openPhoneBook(phoneBook, command);
	return (0);
}
