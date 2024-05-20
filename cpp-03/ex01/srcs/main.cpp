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

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

// Test no hit points. Cannot do anything.
void	john_test(void)
{
	ScavTrap john("John");

	john.display_all();
	john.attack("One");
	john.guardGate();
	john.attack("Two");
	john.attack("Three");
	john.display_all();
	john.takeDamage(40);
	john.display_all();
	john.takeDamage(20);
	john.display_all();
	john.beRepaired(30);
	john.display_all();
	john.takeDamage(40);
	john.takeDamage(33);
	john.display_all();
	john.attack("Should fail attack");
	john.takeDamage(30);
	john.beRepaired(30);
}
int main(void)
{
	john_test();
	return 0;
}
