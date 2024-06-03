/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:08:24 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/03 17:19:28 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please provide ONE argument\n";
		return (1);
	}
	ScalarConverter::convert(static_cast<std::string>(argv[1]));
	return 0;
}
