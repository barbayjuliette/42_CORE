/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:13:57 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/25 15:23:11 by jbarbay          ###   ########.fr       */
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
	std::cout << "Default constructor called for: " << this->_name << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Constructor called for: " << this->_name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Deconstructor called for: " << this->_name << std::endl;
}
