/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:56:22 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/14 18:14:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>



// void replace_line(std::string line, std::ofstream& replace_line, char const *argv[])
// {
// 	std::string	s1 = argv[2];
// 	std::string	s2 = argv[3];
// 	int	i = 0;
// 	int	s1_len = s1.length();

// 	int line_len = line.length();

// 	while (i < line_len)
// 	{
// 		int pos = line.find(s1, i);
// 		if (pos == i)
// 		{
// 			replace_line << s2;
// 			i += s1_len;
// 		}
// 		else
// 		{
// 			replace_line << line[i];
// 			i++;
// 		}
// 	}
// 	replace_line << "\n";
// }

void replace_text(std::ofstream& replace_file, std::ifstream& my_file, char const *argv[])
{
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	int			i = 0;
	int			s1_len = s1.length();
	char		character;

	while (my_file.get(character))
	{
		int pos = line.find(s1, i);
		if (pos == i)
		{
			replace_file << s2;
			i += s1_len;
		}
		else
		{
			replace_file << line[i];
			i++;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::string	filename = argv[1];
	std::string	line;
	std::string	new_line;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	std::ofstream replace_file("replace.txt");
	std::ifstream my_file(filename);

	replace_text(replace_file, my_file, argv);
	// while (getline(my_file, line))
	// {
	// 	replace_line(line, replace_file, argv);
	// }
	my_file.close();
	replace_file.close();

	return 0;
}

// Error: file does not exit
// Error: failed to open