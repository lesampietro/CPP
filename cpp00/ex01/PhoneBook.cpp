/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:07:34 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 00:57:16 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::addContact()
{
	static int i;
	this->contacts[i].createContact();
	if (this->contacts[i].isContactEmpty())
	{
		std::cout << "Contact not created. Try again." << RST << std::endl;
		this->contacts[i].clearContact();
		return;
	}
	i = (i + 1) % 8;
	return;
}

void PhoneBook::searchContact()
{
	int			index = 0;
	int			inputNumber = 0;
	std::string	inputString;
	
	if (!displayContacts())
		return ;
	while (1)
	{
		std::cout << YELLOW << "\nEnter your contact index: " << RST;
		std::getline(std::cin, inputString);
		if (std::cin.eof())
		{
			std::cout << MAGENTA << "\nCtrl+D - Program exited" << RST << std::endl;
			exit(0);
		}
		inputNumber = stringToInt(inputString);
		if (inputNumber > 8 || inputNumber < 1){
			std::cout << MAGENTA << "\nIndex out of range. Please enter a number between 1 and 8." << RST << std::endl;
		}
		else if (this->contacts[inputNumber - 1].isContactEmpty())
		{
			std::cout << MAGENTA << "\nThis contact does not exist." << RST << std::endl;
		}
		else
		{
			while (index < 8 && !this->contacts[index].isContactEmpty())
			{
				if ((index + 1) == inputNumber)
				{
					this->getContactByIndex(inputNumber);
				}
				index++;
			}
			break ;
		}
		std::cout << "Type anything to continue..." << RST << std::endl;
		std::string temp;
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << MAGENTA << "\nCtrl+D - Program exited" << RST << std::endl;
			exit(0);
		}
	}
}

void	PhoneBook::getContactByIndex(int &index)
{
	int arrayIndex = index - 1;
	
	std::cout << GREEN << "\n|" << std::setw(44);
	std::cout << std::right << "CONTACT INFO|" << RST << std::endl;
	std::cout << "|" << std::setw(43) << std::right;
	std::cout << this->contacts[arrayIndex].getFirstName() << "|" << std::endl;
	std::cout << "|" << std::setw(43) << std::right;
	std::cout << this->contacts[arrayIndex].getLastName() << "|" << std::endl;
	std::cout << "|" << std::setw(43) << std::right;
	std::cout << this->contacts[arrayIndex].getNickName() << "|" << std::endl;
	std::cout << "|" << std::setw(43) << std::right;
	std::cout << this->contacts[arrayIndex].getPhoneNumber() << "|" << std::endl;
	std::cout << "|" << std::setw(43) << std::right;
	std::cout << this->contacts[arrayIndex].getDarkestSecret() << "|" << std::endl;
}

bool PhoneBook::displayContacts()
{
	int index = 0;

	std::cout << GREEN << "\n|" << std::setw(10) << std::right << "INDEX";
	std::cout << "|" << std::setw(10) << std::right << "FIRST NAME";
	std::cout << "|" << std::setw(10) << std::right << "LAST NAME";
	std::cout << "|" << std::setw(10) << std::right << "NICKNAME" << "|" << RST << std::endl;
	while (index < 8 && !this->contacts[index].isContactEmpty()) // checks if there are contacts to be shown - if so, increments index
	{
		// index
		std::cout << "|" << std::setw(10) << index + 1;
		// firstName
		std::string firstName = this->contacts[index].getFirstName();
		if (firstName.length() > 10)
		{
			std::cout << "|" << std::right << firstName.substr(0, 9) << ".";
		}
		else
			std::cout << "|" << std::setw(10) << std::right << firstName;
		// lastName
		std::string lastName = this->contacts[index].getLastName();
		if (lastName.length() > 10)
			std::cout << "|" << std::right << lastName.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << std::right << lastName;
		// nickName
		std::string nickName = this->contacts[index].getNickName();
		if (nickName.length() > 10)
			std::cout << "|" << std::right << nickName.substr(0, 9) << ".|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << std::right << nickName << "|" << std::endl;
		index++;
	}
	if (index == 0){
		std::cout << "\nContact list is empty." << std::endl;
		return false;
	}
	return true;
}

int PhoneBook::stringToInt(const std::string &str)
{
	int		result = 0;
	int		sign = 1;
	size_t	i = 0;

	while(i < str.length() && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (i < str.length() && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < str.length() && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * sign;
}
