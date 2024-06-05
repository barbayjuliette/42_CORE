/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:59:59 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/05 19:33:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
#include <stdexcept>
#define WHITE "\e[0;97m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define BBLUE "\e[1;36m"
#define BLUE "\e[0;36m"

template <typename T>
class Array
{
	private:
		T				*array;
		unsigned int	len;
	public:
		Array(): array(NULL), len(0) {}

		Array(const Array& src) : array(new T[src.len]), len(src.len)
		{
			unsigned int	i = 0;
			while (i < src.len)
			{
				this->array[i] = src.array[i];
				i++;
			}
		}

		~Array()
		{
			delete[] array;
		}

		Array(unsigned int n) : len(n)
		{
			array = new T[n];
		}

		Array&	operator=(Array const &rhs)
		{
			if (this == &rhs)
				return *this;

			unsigned int	i = 0;
			this->len = rhs.len;
			delete[] array;
			this->array = new T[this->len];

			while (i < rhs.len)
			{
				this->array[i] = rhs.array[i];
				i++;
			}
			return *this;
		}

		unsigned int size(void)
		{
			return (this->len);
		}

		T&	operator[](unsigned int index)
		{
			if (index >= this->len || index < 0)
				throw std::runtime_error("Index is out of bound");
			return (this->array[index]);
		}

		void	print_array(void)
		{
			unsigned int i = 0;
			while (i < this->len)
			{
				std::cout << "Element [" << i << "]: " << this->array[i] << std::endl;
				i++;
			}
		}
};

#endif
