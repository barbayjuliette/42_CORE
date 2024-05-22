/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:23:08 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 16:40:34 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/colors.hpp"

void	test_animals()
{	
	std::cout << RED << "---First test: should print the specific sounds of the Dog and Cat---" << WHITE << std::endl;
	std::cout << GREEN << "Construction:" << WHITE << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << GREEN << "Types:" << WHITE << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl << std::endl;

	std::cout << GREEN << "Should be cat sound: " << WHITE << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << GREEN << "Should be dog sound: " << WHITE << std::endl;
	j->makeSound();
	std::cout << GREEN << "Should be animal sound: " << WHITE << std::endl;
	meta->makeSound();

	std::cout << std::endl << GREEN << "Destruction:" << WHITE << std::endl;
	delete meta;
	delete j;
	delete i;
}

void	test_wrong_animals()
{	
	std::cout << RED << "---Second test: should print the sound of Wrong Animal, not Wrong Cat/Dog---" << WHITE << std::endl;
	std::cout << GREEN << "Construction:" << WHITE << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << std::endl << GREEN << "Types:" << WHITE << std::endl;
	std::cout << i->getType() << " " << std::endl << std::endl;
	
	std::cout << GREEN << "Should all be Animal sound: " << WHITE << std::endl;
	i->makeSound();
	meta->makeSound();

	std::cout << std::endl << GREEN << "Destruction:" << WHITE << std::endl;
	delete meta;
	delete i;
}

void	extra_tests()
{
	std::cout << RED << "--- Extra tests: ---" << WHITE << std::endl;

	std::cout << GREEN << "Animal contruction" << WHITE << std::endl;
	const Animal* meta = new Animal();
	std::cout << GREEN << "Dog contruction" << WHITE << std::endl;
	const Dog dog;
	std::cout << GREEN << "Cat contruction" << WHITE << std::endl;
	const Cat cat;
	std::cout << GREEN << "Copy cat contruction" << WHITE << std::endl;
	const Cat copy_cat(cat);
	std::cout << GREEN << "Puppy contruction" << WHITE << std::endl;
	Dog puppy;
	puppy = dog;

	std::cout << std::endl << GREEN << "Types and sounds:" << WHITE << std::endl;
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

	std::cout << std::endl << GREEN << "Destruction:" << WHITE << std::endl;
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