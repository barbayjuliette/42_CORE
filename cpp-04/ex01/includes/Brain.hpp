/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:19 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 16:18:20 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(const Brain& src);
		virtual ~Brain();

		Brain&			operator=( Brain const & rhs );

		const std::string*	get_ideas() const;
		void	set_ideas(std::string idea);
		void	print_ideas() const;
};

#endif