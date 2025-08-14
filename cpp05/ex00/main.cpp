/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/08/14 15:29:33 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"


int	main() {
	Bureaucrat bureau("Bobby", 1);
	Bureaucrat bureau2("Bobby2", 150);
	Bureaucrat bureau3("Bobby3", 0);
	Bureaucrat bureau4("Bobby4", 200);

	std::cout << std::endl;
	std::cout << bureau << " has grade: " << bureau.getGrade() << std::endl;
	std::cout << bureau2 << " has grade: " << bureau2.getGrade() << std::endl;
	std::cout << bureau3 << " has grade: " << bureau3.getGrade() << std::endl;
	std::cout << bureau4 << " has grade: " << bureau4.getGrade() << std::endl;
	std::cout << std::endl;

	return 0;
}
