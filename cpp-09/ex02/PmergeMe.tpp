/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:28:40 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/14 20:53:10 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
T	create_container(char *argv[], int argc)
{
	T		unsorted;
	int		i = 1;
	int		n;

	while (i < argc)
	{
		n = std::atoi(argv[i]);
		if (n <= 0)
			throw (std::runtime_error("Error: wrong input"));
		unsorted.push_back(n);
		i++;
	}
	return (unsorted);
}
