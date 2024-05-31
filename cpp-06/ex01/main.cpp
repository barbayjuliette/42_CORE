/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:56:06 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 17:26:20 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main(void)
{
	t_data		*data = new t_data;
	uintptr_t	u_int;

	data->num = 5;
	
	std::cout << "Address: " << data << std::endl;
	
	u_int = Serializer::serialize(data);
	data = Serializer::deserialize(u_int);

	std::cout << "Num is: " << data->num << std::endl;
	std::cout << "Address: " << data << std::endl;
	
	delete data;
	return (0);
}
