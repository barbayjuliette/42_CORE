/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:26:30 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/29 12:18:36 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	// std::cout << "Constructor called" << std::endl;
}

Harl::~Harl(void)
{
	// std::cout << "Deconstructor called" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "This is a debug message" << std::endl;
}
void	Harl::info( void )
{
	std::cout << "This is an informative message" << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "WARNING, please be careful!" << std::endl;
}
void	Harl::error( void )
{
	std::cout << "Oops, there was an error" << std::endl;
}

// I create pointers to the member functions
//  I create an array of pointers to the member functions
//  I call the right function

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
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
