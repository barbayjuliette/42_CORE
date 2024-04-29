/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:49:46 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/25 16:51:55 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		void	announce(void);
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
