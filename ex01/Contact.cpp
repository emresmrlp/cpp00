/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:01:05 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/23 19:32:42 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	FirstName = "";
	LastName = "";
	Nickname = "";
	PhoneNumber = "";
	DarkestSecret = "";
}

Contact::Contact(std::string FirstName, std::string LastName,
	std::string Nickname, std::string PhoneNumber,
	std::string DarkestSecret)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Nickname = Nickname;
	this->PhoneNumber = PhoneNumber;
	this->DarkestSecret = DarkestSecret;
}

std::string Contact::getFirstName() const
{
	return (FirstName);
}

std::string Contact::getLastName() const
{
	return (LastName);
}

std::string Contact::getNickname() const
{
	return (Nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (PhoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (DarkestSecret);
}
