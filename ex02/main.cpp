/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:51:01 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 21:37:41 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	std::cout << " * Can create Dog as AAnimal:" << std::endl;
	AAnimal *dog = new Dog();
	std::cout << std::endl << " * Can create Cat as AAnimal:" << std::endl;
	AAnimal *cat = new Cat();
	std::cout << std::endl << " * But cannot create AAnimal as AAnimal since it is abstract " 
						   << "(See comment in code...)" << std::endl;
	// AAnimal *animal = new AAnimal(); // This is not allowed. Uncomment to see compiler issue

	std::cout << std::endl;
	std::cout << " * Deleting allocated cat and dog:" << std::endl;
	delete dog;
	delete cat;

	return 0;
}
