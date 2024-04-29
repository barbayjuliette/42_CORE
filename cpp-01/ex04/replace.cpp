/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:14:43 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/25 18:19:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void replace_text(std::string str, char *argv[])
{
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	int			i = 0;
	int			s1_len = s1.length();

	std::ofstream outfile("new.txt");
	if (!outfile.is_open())
	{
		std::cerr << "Failed to create output file" << std::endl;
		perror("");
		exit(1);
	}
	while (str[i])
	{
		int pos = str.find(s1, i);
		if (pos == i)
		{
			outfile << s2;
			i += s1_len;
		}
		else
		{
			outfile << str[i];
			i++;
		}
	}
	outfile.close();
}

int	replace_file(char *argv[])
{
	std::string	str;
	char	c;

	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		perror("");
		return (1);
	}
	while (infile.get(c))
		str += c;
	infile.close();
	replace_text(str, argv);
	return (0);
}