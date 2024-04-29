/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:14:46 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/25 16:59:16 by jbarbay          ###   ########.fr       */
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
	Zombie* zombies = zombieHorde(n, "Juliette");
	while (i < n)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
	return 0;
}
