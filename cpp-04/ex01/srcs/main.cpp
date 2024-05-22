/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:23:08 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 17:16:14 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/colors.hpp"

void	test_pet_array()
{
	std::cout << RED << "---Create array of 10 Animals, half Cats, half Dogs---" << WHITE << std::endl;
	
	std::cout << GREEN << "Creating array" << WHITE << std::endl;
	Animal* pets[10];

	std::cout << GREEN << "Create 5 Cats:" << WHITE << std::endl;
	int	i = 0;
	while (i < 5)
	{
		pets[i] = new Cat();
		i++;
	}
	
	std::cout << std::endl << GREEN << "Create 5 Dogs:" << WHITE << std::endl;
	while (i < 10)
	{
		pets[i] = new Dog();
		i++;
	}

	std::cout << std::endl << GREEN << "Loop through array and each makes sound:" << WHITE << std::endl;
	i = 0;
	while (i < 10)
	{
		std::cout << "Pet " << i << " is a " << pets[i]->getType() << " and its sound is ";
		pets[i]->makeSound();
		i++;
	}

	std::cout << std::endl << GREEN << "Destruction:" << WHITE << std::endl;
	i = 0;
	while (i < 10)
	{
		std::cout << GREEN << i << WHITE << std::endl;
		delete pets[i];
		i++;
	}
}

void	test_deep_copy_cat()
{
	std::cout << RED << "---Make sure copy is deep, not shallow!- CAT ---" << WHITE << std::endl;
	
	std::cout << GREEN << "Creating 1 cat" << WHITE << std::endl;
	Cat cat;
	std::cout << std::endl << GREEN << "Adding 3 ideas to cat" << WHITE << std::endl;
	cat.get_brain()->set_ideas("First idea");
	cat.get_brain()->set_ideas("Second idea");
	cat.get_brain()->set_ideas("Third idea");

	std::cout << std::endl << GREEN << "Creating 1 kitten" << WHITE << std::endl;
	Cat kitten(cat);
	
	std::cout << std::endl << GREEN << "Adding 1 idea to cat\n" << WHITE << std::endl;
	cat.get_brain()->set_ideas("Stupid idea");

	std::cout << GREEN << "Printing all the ideas of cat" << WHITE << std::endl;
	cat.get_brain()->print_ideas();
	
	std::cout << std::endl << GREEN << "Printing all the ideas of kitten" << WHITE << std::endl;
	kitten.get_brain()->print_ideas();

	std::cout << std::endl << GREEN << "Destruction:" << WHITE << std::endl;
}

void	test_deep_copy_dog()
{
	std::cout << RED << "---Make sure copy is deep, not shallow!- DOG---" << WHITE << std::endl;
	
	std::cout << GREEN << "Creating 1 dog" << WHITE << std::endl;
	Dog dog;

	std::cout << std::endl << GREEN << "Creating 1 puppy" << WHITE << std::endl;
	Dog puppy(dog);
	
	std::cout << std::endl << GREEN << "Adding 3 ideas to dog" << WHITE << std::endl;
	dog.get_brain()->set_ideas("First idea");
	dog.get_brain()->set_ideas("Second idea");
	dog.get_brain()->set_ideas("Third idea");

	std::cout << std::endl << GREEN << "Adding 1 idea to puppy\n" << WHITE << std::endl;
	puppy.get_brain()->set_ideas("Stupid idea");

	std::cout << GREEN << "Printing all the ideas of dog" << WHITE << std::endl;
	dog.get_brain()->print_ideas();
	
	std::cout << std::endl << GREEN << "Printing all the ideas of puppy" << WHITE << std::endl;
	puppy.get_brain()->print_ideas();

	std::cout << std::endl << GREEN << "Destruction:" << WHITE << std::endl;
}

void	test_deep_copy_type()
{
	std::cout << RED << "---Make sure copy is deep, not shallow!- TYPE---" << WHITE << std::endl;
	
	std::cout << GREEN << "Creating 1 dog" << WHITE << std::endl;
	Dog dog;

	std::cout << std::endl << GREEN << "Creating 1 puppy" << WHITE << std::endl;
	Dog puppy;

	puppy = dog;
	std::cout << std::endl << GREEN << "Changing type of puppy: DOG -> PUPPY" << WHITE << std::endl;
	puppy.setType("Puppy");

	std::cout << std::endl << GREEN << "Check types" << WHITE << std::endl;
	std::cout << "Dog is of type: " << dog.getType() << std::endl;
	std::cout << "Puppy is of type: " << puppy.getType() << std::endl;

	std::cout << std::endl << GREEN << "Destruction:" << WHITE << std::endl;

}

int main()
{
	test_pet_array();
	// test_deep_copy_cat();
	// test_deep_copy_dog();
	// test_deep_copy_type();
	return 0;
}