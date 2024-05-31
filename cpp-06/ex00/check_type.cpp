/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:03:49 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 17:36:37 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	get_precision_float(std::string lit)
{
	int	i = 0;
	int	count = 0;
	while (lit[i] != 46)
		i++;
	i++;
	while (lit[i] != 'f' && lit[i])
	{
		i++;
		count++;
	}
	count = ( count == 0 ? 1 : count);
	return (count);
}

int	get_precision_double(std::string lit)
{
	int	i = 0;
	int	count = 0;
	while (lit[i] != 46)
		i++;
	i++;
	while (lit[i])
	{
		i++;
		count++;
	}
	count = ( count == 0 ? 1 : count);
	return (count);
}

int	is_int(std::string lit)
{
	int	i = 0;

	while (lit[i])
	{
		if (!isdigit(lit[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_double(std::string lit)
{
	int	i = 0;

	while (lit[i])
	{	
		if (lit[i] == 46 && i++)
			continue ;
		if (lit[0] < 48 || lit[0] > 57 )
			return (0);
		i++;
	}
	return (1);
}