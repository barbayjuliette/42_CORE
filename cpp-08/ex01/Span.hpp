/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:43:25 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/09 15:21:30 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <algorithm>
# include <limits.h>
# include <time.h>

#define WHITE "\e[0;97m"
#define RED "\e[31m"
#define BBLUE "\e[1;36m"
#define BLUE "\e[0;36m"

void	display_int(int n);

class Span
{

	public:
		std::vector<int> nums;

		Span(unsigned int N);
		Span( Span const & src );
		~Span();
		Span();

		Span &		operator=( Span const & rhs );

		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	print(void) const;

		void	addManyNumbers(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);

	private:
};

#endif