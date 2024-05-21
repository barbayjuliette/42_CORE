/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:23:08 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/21 19:38:49 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

void	test_1()
{	
	const char *red = "\e[31m";
	const char *green = "\e[32m";
	const char *white = "\e[97m";

	std::cout << red << "---First test: should print the specific sounds of the Dog and Cat---" << white << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << green << "Should be cat sound: " << white << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << green << "Should be dog sound: " << white << std::endl;
	j->makeSound();
	std::cout << green << "Should be animal sound: " << white << std::endl;
	meta->makeSound();
}

void	test_2()
{	
	const char *red = "\e[31m";
	const char *white = "\e[97m";
	const char *green = "\e[32m";

	std::cout << red << "---Second test: should print the specific sounds of the Dog and Cat---" << white << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	// const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	// std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << green << "Should all be Animal sound: " << white << std::endl;
	i->makeSound();
	// j->makeSound();
	meta->makeSound();
}

int main()
{
	test_1();
	std::cout << std::endl;
	test_2();
	return 0;
}