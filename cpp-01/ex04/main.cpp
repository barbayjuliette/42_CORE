/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:56:22 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/15 11:52:03 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace_text(std::string str, char const *argv[])
{
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	int			i = 0;
	int			s1_len = s1.length();

	std::ofstream outfile("replace.txt");
	if (!outfile.is_open())
		std::cerr << "Failed to create output file" << std::endl;

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

int main(int argc, char const *argv[])
{
	std::string	str;
	char	c;

	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
	}
	while (infile.get(c))
		str += c;
	infile.close();
	replace_text(str, argv);
	return 0;
}
