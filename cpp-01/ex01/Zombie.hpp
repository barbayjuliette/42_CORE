/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:04:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/20 09:28:42 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		void setName(std::string name);
		void	announce(void);
		Zombie(void);
		~Zombie(void);
		static Zombie*	zombieHorde( int N, std::string name );
};
