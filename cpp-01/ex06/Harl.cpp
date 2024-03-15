/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:02:24 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/15 17:13:54 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]\n" << "This is a debug message" << std::endl;
}
void	Harl::info( void )
{
	std::cout << "[INFO]\n" << "This is an informative message" << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "[WARNING]\n" << "Please be careful!" << std::endl;
}
void	Harl::error( void )
{
	std::cout << "[ERROR]\n" << "Oops, there was an error" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr_debug)() = &Harl::debug;
	void	(Harl::*ptr_info)() = &Harl::info;
	void	(Harl::*ptr_warning)() = &Harl::warning;
	void	(Harl::*ptr_error)() = &Harl::error;

	void	(Harl::*ptr_complain[4])() = {ptr_debug, ptr_info, ptr_warning, ptr_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*ptr_complain[i])();
			return ;
		}
		i++;
	}
}
