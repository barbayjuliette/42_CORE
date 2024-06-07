/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:43:48 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/07 19:03:35 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

#define WHITE "\e[0;97m"
#define BLUE "\e[0;36m"

template<class T>
class MutantStack : public std::stack<T>
{

	public:
		typedef std::stack<T> stack;
		typedef	typename stack::container_type container;
		typedef typename container::iterator iterator;
    	typedef typename container::const_iterator const_iterator;
		MutantStack(){};
		MutantStack( MutantStack const & src )
		{
			*this = src;
		};
		~MutantStack(){};

		MutantStack &		operator=( MutantStack const & rhs )
		{
			*this = rhs;
			return (*this);
		};

		iterator begin()
		{
			return (stack::c.begin());
		}

		const_iterator begin() const
		{
			return (stack::c.begin());
		}

		iterator end()
		{
			return (stack::c.end());
		}

		const_iterator end() const
		{
			return (stack::c.end());
		}
};

#endif
