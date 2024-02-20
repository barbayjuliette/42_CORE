/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:13:57 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/19 19:19:00 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Constructor called with name" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Deconstructor called" << std::endl;
}
