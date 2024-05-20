/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:20:59 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 21:15:17 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

void	john_test(void)
{
	DiamondTrap john("John");
	john.display_all();
	john.attack("One");
	john.attack("Two");
	john.attack("Three");
	john.takeDamage(4);
	john.takeDamage(2);
	john.beRepaired(3);
	john.takeDamage(4);
	john.takeDamage(3);
	john.beRepaired(3);
	john.display_all();
}

int main(void)
{
	john_test();
	return 0;
}
