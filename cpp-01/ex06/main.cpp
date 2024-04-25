/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:02:28 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/25 19:14:41 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"

int	get_num(std::string level)
{
	int	i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 4)
	{
		if (level == levels[i])
			return (i);
		i++;
	}
	return (-1);
}

//  If the break keyword is NOT present, then all the cases after the matching case are executed.
// Switch statement can only be used with int and char

void	display_msg(std::string level, Harl& instance)
{
	switch (get_num(level))
	{
	case 0:
		instance.complain("DEBUG");
	case 1:
		instance.complain("INFO");
	case 2:
		instance.complain("WARNING");
	case 3:
		instance.complain("ERROR");
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	Harl instance;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	display_msg(argv[1], instance);
	return (0);
}
