/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:14:46 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/20 09:30:08 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	int	i;
	int	n;

	n = 5;
	i = 0;
	Zombie* zombies = Zombie::zombieHorde(n, "Juliette");
	while (i < n)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
	return 0;
}
