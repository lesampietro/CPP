/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:07:34 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 00:37:05 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::createContact()
{
	std::cout << YELLOW << "Type your first name: " << RST;
	std::getline(std::cin, firstName);
	checkEof();
	if (isFieldEmpty(firstName))
		return ;
	if (!isValidName(firstName))
		return ;
	firstName = toUpperCase(firstName);
	std::cout << YELLOW << "Type your last name: " << RST;
	std::getline(std::cin, lastName);
	checkEof();
	if (isFieldEmpty(lastName))
		return ;
	if (!isValidName(lastName))
		return;
	lastName = toUpperCase(lastName);
	std::cout << YELLOW << "Type your nickname: " << RST;
	std::getline(std::cin, nickName);
	checkEof() ;
	if (isFieldEmpty(nickName))
		return ;
	if (!isValidName(nickName))
		return ;
	nickName = toUpperCase(nickName);
	std::cout << YELLOW << "Type your phone number: " << RST;
	std::getline(std::cin, phoneNumber);
	checkEof();
	if (isFieldEmpty(phoneNumber))
		return ;
	if (phoneNumber.find_first_not_of("0123456789-().") != std::string::npos)
	{
		std::cout << MAGENTA << "Invalid phone number. Please enter only digits." << RST << std::endl;
		return;
	}
	std::cout << YELLOW << "Type your darkest secret: " << RST;
	std::getline(std::cin, darkestSecret);
	checkEof();
	if (isFieldEmpty(darkestSecret))
		return ;
	if (!isValidName(darkestSecret))
		return;
	darkestSecret = toUpperCase(darkestSecret);
}

std::string	Contact::toUpperCase(const std::string &str)
{
	std::string result = str;
	size_t i = 0;

	while (i < result.length())
	{
		if (result[i] >= 'a' && result[i] <= 'z')
			result[i] = result[i] - 32;
		i++;
	}
	return result;
}

bool	Contact::isFieldEmpty(const std::string &str)
{
	if (str.empty() || str.find_first_not_of(" ") == std::string::npos \
		|| firstName.find_first_not_of("\t") == std::string::npos)
	{
		std::cout << MAGENTA << "Field cannot be empty.";std::cout << RST << std::endl;
		this->clearContact();
		return (true);
	}
	return (false);
}

bool	Contact::isValidName(const std::string &str)
{
	size_t i = 0;
	
	while (i < str.length())
	{
		if (!std::isalnum(str[i]) && !std::isprint(str[i]))
		{
			std::cout << MAGENTA << "Data cannot contain accented characters." << RST << std::endl;
			this->clearContact();
			return false;
		}
		i++;
	}
	return true;
}

void	Contact::clearContact()
{
	firstName.clear();
	lastName.clear();
	nickName.clear();
	phoneNumber.clear();
	darkestSecret.clear();
}

bool	Contact::isContactEmpty() const
{
	return firstName.empty() || lastName.empty() || nickName.empty() \
	|| phoneNumber.empty() || darkestSecret.empty();
}

void	Contact::checkEof()
{
	if (std::cin.eof())
	{
		std::cout << MAGENTA << "\nCtrl+D - Program exited" << RST << std::endl;
		std::exit(0);
	}
}

std::string	Contact::getFirstName() const
{
	return firstName;
}

std::string	Contact::getLastName() const
{
	return lastName;
}

std::string	Contact::getNickName() const
{
	return nickName;
}

std::string	Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return darkestSecret;
}
