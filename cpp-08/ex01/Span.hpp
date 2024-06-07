/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:43:25 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/07 15:41:14 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
// # include <map>
# include <vector>
// # include <list>
# include <exception>
# include <algorithm>
# include <limits.h>
# include <time.h>

#define WHITE "\e[0;97m"
#define RED "\e[31m"
#define BBLUE "\e[1;36m"
#define BLUE "\e[0;36m"

class Span
{

	public:
		std::vector<int> nums;

		Span();
		Span(unsigned int N);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	print(void) const;

		void	addManyNumbers(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);

	private:
};

#endif