/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:20:59 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 21:15:03 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	second_test(void)
{
	ScavTrap	bob;
	ScavTrap john("John");
	bob.display_all();
	ScavTrap	copy(bob);
	bob.display_all();
	bob.guardGate();
	john = bob;
	std::cout << "Changed name to: " << john.get_name() << std::endl;
}

void	john_test(void)
{
	ScavTrap john("John");
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
	second_test();
	return 0;
}
