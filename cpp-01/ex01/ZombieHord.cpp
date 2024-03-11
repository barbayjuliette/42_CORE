/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:05:49 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/20 09:23:09 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int N, std::string name )
{
	int	i;

	Zombie* zombies = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return zombies;
}
