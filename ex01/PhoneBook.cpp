/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:25:45 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/23 19:32:26 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	NumContacts = 0;
}


void PhoneBook::addContact(std::string FirstName, std::string LastName,
		std::string Nickname, std::string PhoneNumber,
		std::string DarkestSecret)
{
	if (NumContacts < 8)
	{
		contacts[NumContacts] = Contact(FirstName, LastName, Nickname,
			PhoneNumber, DarkestSecret);
		NumContacts++;
	}
	else
	{
		for(int i = 1; i < 8; i++)
			contacts[i - 1] = contacts[i];
		contacts[7] = Contact(FirstName, LastName, Nickname,
			PhoneNumber, DarkestSecret);
	}
}

void	PhoneBook::getContactInfo(int index)
{
	if (index < 1 || index > NumContacts)
		return ;
	std::cout << "First Name: " << contacts[index - 1].getFirstName()
		<< std::endl;
	std::cout << "Last Name: " << contacts[index - 1].getLastName()
		<< std::endl;
	std::cout << "Nickname: " << contacts[index - 1].getNickname()
		<< std::endl;
	std::cout << "Phone Number: " << contacts[index - 1].getPhoneNumber()
		<< std::endl;
	std::cout << "Darkest Secret: " << contacts[index - 1].getDarkestSecret()
		<< std::endl;
}

int	PhoneBook::getNumContacts() const
{
	return (NumContacts);
}

void	PhoneBook::listContact() const
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < NumContacts; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		if (contacts[i].getFirstName().length() > 10)
			std::cout << contacts[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
		if (contacts[i].getLastName().length() > 10)
			std::cout << contacts[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contacts[i].getLastName() << "|";
		if (contacts[i].getNickname().length() > 10)
			std::cout << contacts[i].getNickname().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contacts[i].getNickname() << "|";	
		std::cout << std::endl << "|----------|----------|----------|----------|"
			<< std::endl;
	}
}
