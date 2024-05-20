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

// Test Bob has no energy point. Cannot attack, can only be attacked
void	bob_test(void)
{
	ClapTrap	bob("Bob");

	bob.display_all();
	bob.attack("One");
	bob.attack("Two");
	bob.attack("Three");
	bob.attack("Four");
	bob.attack("Five");
	bob.attack("Six");
	bob.attack("Seven");
	bob.attack("Eight");
	bob.attack("Nine");
	bob.display_all();
	bob.attack("Ten");
	bob.display_all();
	bob.attack("Eleven");
	bob.takeDamage(3);
	bob.takeDamage(5);
	bob.takeDamage(3);
	bob.display_all();
	bob.beRepaired(5);
	bob.takeDamage(3);
}

// Test no hit points. Cannot do anything.
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
	john.attack("Should fail attack");
	john.takeDamage(3);
	john.beRepaired(3);
}

int main(void)
{
	bob_test();
	// john_test();
	return 0;
}
