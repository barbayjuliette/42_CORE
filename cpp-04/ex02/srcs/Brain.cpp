/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:36:15 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 16:26:08 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain constructor called 🧠" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain&		Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain assignment operator called" << std::endl;
	int	i = 0;
	while (!(rhs.get_ideas()[i].empty()) && i < 100)
	{
		this->_ideas[i] = rhs._ideas[i];
		i++;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	Brain::print_ideas() const
{
	int	i = 0;
	while (!(this->_ideas[i].empty()) && i < 100)
	{
		std::cout << "Idea " << i << ": "<< _ideas[i] << std::endl;
		i++;
	}
	if (i == 0)
		std::cout << "No ideas inside this brain" << std::endl;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string*	Brain::get_ideas() const
{
	return (_ideas);
}

void	Brain::set_ideas(std::string idea)
{
	int	i = 0;

	while (!(this->_ideas[i].empty()) && i < 100)
		i++;
	if (i == 99)
	{
		std::cout << "Brain is already full of ideas" << std::endl;
		return ;
	}
	this->_ideas[i] = idea;
}

/* ************************************************************************** */