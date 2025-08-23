/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:34:45 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/23 18:35:14 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
public:
	Contact();
	Contact(std::string FirstName, std::string LastName,
		std::string Nickname, std::string PhoneNumber,
		std::string DarkestSecret);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
private:
	std::string	FirstName;
	std::string	LastName;
	std::string Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
};

#endif