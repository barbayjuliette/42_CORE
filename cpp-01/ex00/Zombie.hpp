/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:49:46 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/20 08:58:58 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string	_name;
		Zombie(void);
	public:
		void	announce(void);
		static Zombie* newZombie( std::string name );
		static void randomChump( std::string name );
		Zombie(std::string name);
		~Zombie(void);
};
