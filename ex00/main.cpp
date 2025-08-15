/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:51:01 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 20:34:04 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	std::cout << "=============== Checking with right Animal class ===============" << std::endl;
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << std::endl << "=============== Checking types ===============" << std::endl;
		std::cout << "Dog:    \'" << j->getType() << "\'" << std::endl;
		std::cout << "Cat:    \'" << i->getType() << "\'" << std::endl;
		std::cout << "Animal: \'" << meta->getType() << "\'" << std::endl;

		std::cout << std::endl << "=============== Checking sounds ===============" << std::endl;
		std::cout << "== Cat:" << std::endl;
		i->makeSound(); // will output the cat sound!
		std::cout << "== Dog:" << std::endl;
		j->makeSound();
		std::cout << "== Animal:" << std::endl;
		meta->makeSound();
		std::cout << std::endl;

		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl << "=============== Checking with wrong Animal class ===============" << std::endl;
	{
		const WrongAnimal *wrongAnimal = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << std::endl << "=============== Checking types ===============" << std::endl;
		std::cout << "Cat:    \'" << wrongCat->getType() << "\'" << std::endl;
		std::cout << "Animal: \'" << wrongAnimal->getType() << "\'" << std::endl;

		std::cout << std::endl << "=============== Checking sounds ===============" << std::endl;
		std::cout << "== Cat:" << std::endl;
		wrongCat->makeSound();
		std::cout << "== Animal:" << std::endl;
		wrongAnimal->makeSound();
		std::cout << std::endl;

		delete wrongAnimal;
		delete wrongCat;
	}

	return 0;
}
