/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:14:54 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/11 11:12:10 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

<<<<<<< HEAD:gnl_exam/get_next_line.h
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlcpy(char *dest, char *src, int destsize);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*update_rem(char *rem);
char	*get_one_line(char *rem);
=======
class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		Weapon(void);
		~Weapon(void);
		const std::string&	getType(void) const;
		void	setType(std::string type);
};
>>>>>>> 17dd26950d6a657d6c066992e3f171e286a6695d:cpp-01/ex03/Weapon.hpp

#endif
