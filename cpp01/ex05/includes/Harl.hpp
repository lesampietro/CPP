/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:19:56 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/19 16:14:10 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class	Harl{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif