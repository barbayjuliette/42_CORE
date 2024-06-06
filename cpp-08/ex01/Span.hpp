/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:43:25 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/06 19:00:23 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <list>
# include <exception>
# include <algorithm>
# include <limits.h>
# include <bits/stdc++.h>
# include <time.h>

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

		void	addManyNumbers(std::vector<int> toAddNum);

	private:
};

#endif