/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:23:08 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 12:29:01 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

void	test_animals()
{	
	const char *red = "\e[31m";
	const char *green = "\e[32m";
	const char *white = "\e[97m";

	std::cout << red << "---First test: should print the specific sounds of the Dog and Cat---" << white << std::endl;
	std::cout << green << "Construction:" << white << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << green << "Types:" << white << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl << std::endl;

	std::cout << green << "Should be cat sound: " << white << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << green << "Should be dog sound: " << white << std::endl;
	j->makeSound();
	std::cout << green << "Should be animal sound: " << white << std::endl;
	meta->makeSound();

	std::cout << std::endl << green << "Destruction:" << white << std::endl;
	delete meta;
	delete j;
	delete i;
}

void	test_wrong_animals()
{	
	const char *red = "\e[31m";
	const char *white = "\e[97m";
	const char *green = "\e[32m";

	std::cout << red << "---Second test: should print the sound of Wrong Animal, not Wrong Cat/Dog---" << white << std::endl;
	std::cout << green << "Construction:" << white << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << std::endl << green << "Types:" << white << std::endl;
	std::cout << i->getType() << " " << std::endl << std::endl;
	
	std::cout << green << "Should all be Animal sound: " << white << std::endl;
	i->makeSound();
	meta->makeSound();

	std::cout << std::endl << green << "Destruction:" << white << std::endl;
	delete meta;
	delete i;
}

void	extra_tests()
{
	const char *red = "\e[31m";
	const char *white = "\e[97m";
	const char *green = "\e[32m";

	std::cout << red << "--- Extra tests: ---" << white << std::endl;

	std::cout << green << "Animal contruction" << white << std::endl;
	const Animal* meta = new Animal();
	std::cout << green << "Dog contruction" << white << std::endl;
	const Dog dog;
	std::cout << green << "Cat contruction" << white << std::endl;
	const Cat cat;
	std::cout << green << "Copy cat contruction" << white << std::endl;
	const Cat copy_cat(cat);
	std::cout << green << "Puppy contruction" << white << std::endl;
	Dog puppy;
	puppy = dog;

	std::cout << std::endl << green << "Types and sounds:" << white << std::endl;
	std::cout << "The dog is a " << dog.getType() <<  " and sounds like: ";
	dog.makeSound();
	std::cout << "The puppy is a " << puppy.getType() <<  " and sounds like: ";
	puppy.makeSound();
	std::cout << "The cat is a " << cat.getType() << " and sounds like: ";
	cat.makeSound();
	std::cout << "The copy cat is a " << copy_cat.getType() << " and sounds like: ";
	copy_cat.makeSound();
	std::cout << "The animal is a " << meta->getType() << " and sounds like: ";
	meta->makeSound();

	std::cout << std::endl << green << "Destruction:" << white << std::endl;
	delete meta;
}

int main()
{
	// test_animals();
	// std::cout << std::endl;
	// test_wrong_animals();
	// std::cout << std::endl;
	extra_tests();
	return 0;
}