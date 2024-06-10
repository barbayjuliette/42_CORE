/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:21:01 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/10 21:47:56 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	RNP	exp(argv[1]);
	try
	{
		exp.check_errors();
		exp.process_stack();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}