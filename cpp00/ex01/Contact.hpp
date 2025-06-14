/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:20:13 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 00:16:51 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "PhoneBook.hpp"

class Contact {
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	public:
	Contact(void);
	~Contact(void);
	
	void		createContact();
	void		clearContact();
	void		checkEof();
	bool		isContactEmpty() const;
	bool		isValidName(const std::string &str);
	bool		isFieldEmpty(const std::string &str);
	std::string	toUpperCase(const std::string &str);

	// Getters for private members
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
};

#endif