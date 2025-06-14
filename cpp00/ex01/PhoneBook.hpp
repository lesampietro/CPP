/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:20:13 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 00:52:59 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <cctype>
# include "Contact.hpp"

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class PhoneBook{
	private:
		Contact	contacts[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void		addContact();
		void		searchContact();
		bool		displayContacts();
		void		getContactByIndex(int &index);
		int			stringToInt(const std::string &str);
};

#endif