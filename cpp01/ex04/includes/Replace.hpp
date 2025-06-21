/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:47:07 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 16:35:59 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BOLD "\033[1;37m"
# define MAGENTA "\033[0;35m"
# define RST "\033[0m"

bool	replace(const std::string &filename, \
				const std::string &oldStr, const std::string &newStr);

#endif