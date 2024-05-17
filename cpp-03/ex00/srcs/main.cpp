/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:20:59 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 11:15:24 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

void	bob_test(void)
{
	ClapTrap	bob("Bob");

	bob.attack("One");
	bob.attack("Two");
	bob.attack("Three");
	bob.attack("Four");
	bob.attack("Five");
	bob.attack("Six");
	bob.attack("Seven");
	bob.attack("Eight");
	bob.attack("Nine");
	std::cout << "Energy points ClapTrap " << bob.get_name() << ": " << bob.get_energy_points() << std::endl;
	bob.attack("Ten");
	std::cout << "Energy points ClapTrap " << bob.get_name() << ": " << bob.get_energy_points() << std::endl;
	bob.attack("Eleven");
	bob.takeDamage(3);
	bob.takeDamage(5);
	bob.takeDamage(3);
	std::cout << "Hit points ClapTrap " << bob.get_name() << ": " << bob.get_hit_points() << std::endl;
	bob.beRepaired(5);
}

void	john_test(void)
{
	ClapTrap john("John");

	john.display_all();
	john.attack("One");
	john.attack("Two");
	john.attack("Three");
	john.display_all();
	john.takeDamage(4);
	john.display_all();
	john.takeDamage(2);
	john.display_all();
	john.beRepaired(3);
	john.display_all();
	john.takeDamage(4);
	john.takeDamage(3);
	john.display_all();
	john.beRepaired(3);
}

int main(void)
{
	// bob_test();
	john_test();
	return 0;
}
