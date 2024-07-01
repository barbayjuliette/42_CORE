/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:07:38 by jbarbay           #+#    #+#             */
/*   Updated: 2024/07/01 16:53:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: Please enter a list of numbers.\n";
		return (1);
	}
	try
	{
		PmergeMe pm(argv, argc, "vector");
		PmergeMe pl(argv, argc, "list");
		pm.print_result();
		pm.print_time();
		pl.print_time();
		if (!is_sorted(pm.get_sorted_list()) || !is_sorted(pm.get_sorted_vector()))
			throw(std::runtime_error("Did not sort correctly"));
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Error: "<< e.what() << '\n' << WHITE;
	}
	return 0;
}
