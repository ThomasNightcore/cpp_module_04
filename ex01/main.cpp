/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:51:01 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 19:34:40 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

static void checkDog(void)
{
	std::cout << "========== Checking DOG copy constructor ==========" << std::endl;
	Dog *guy1 = new Dog();
	guy1->fillIdeas(5);
	
	std::cout << std::endl << " * dog 1 ideas:" << std::endl;
	guy1->showIdeas();

	std::cout << std::endl;
	Dog *guy2 = new Dog(*guy1);

	std::cout << std::endl << " * dog 2 ideas:" << std::endl;
	guy2->showIdeas();

	std::cout << std::endl << " * deleting dog 1:" << std::endl;
	delete guy1;

	std::cout << std::endl << " * dog 2 ideas:" << std::endl;
	guy2->showIdeas();


	std::cout << std::endl << "========== Checking DOG assignement ==========" << std::endl;
	Dog *guy3 = new Dog();
	std::cout << std::endl << " * dog 3 ideas:" << std::endl;
	guy3->showIdeas();
	std::cout << std::endl;

	*guy3 = *guy2;

	std::cout << std::endl << " * deleting dog 2:" << std::endl;
	delete guy2;

	std::cout << std::endl << " * dog 3 ideas:" << std::endl;
	guy3->showIdeas();

	std::cout << std::endl << " * deleting dog 3:" << std::endl;
	delete guy3;
}

static void checkCat(void)
{
	std::cout << "========== Checking CAT copy constructor ==========" << std::endl;
	Cat *guy1 = new Cat();
	guy1->fillIdeas(3);
	
	std::cout << std::endl << " * cat 1 ideas:" << std::endl;
	guy1->showIdeas();

	std::cout << std::endl;
	Cat *guy2 = new Cat(*guy1);

	std::cout << std::endl << " * cat 2 ideas:" << std::endl;
	guy2->showIdeas();

	std::cout << std::endl << " * deleting cat 1:" << std::endl;
	delete guy1;

	std::cout << std::endl << " * cat 2 ideas:" << std::endl;
	guy2->showIdeas();


	std::cout << std::endl << "========== Checking CAT assignement ==========" << std::endl;
	Cat *guy3 = new Cat();
	std::cout << std::endl << " * cat 3 ideas:" << std::endl;
	guy3->showIdeas();
	std::cout << std::endl;

	*guy3 = *guy2;

	std::cout << std::endl << " * deleting cat 2:" << std::endl;
	delete guy2;

	std::cout << std::endl << " * cat 3 ideas:" << std::endl;
	guy3->showIdeas();

	std::cout << std::endl << " * deleting cat 3:" << std::endl;
	delete guy3;
}

int main()
{
	std::cout << "====================================="
			  << " Checking Dog deep copy " 
			  << "=====================================" 
			  << std::endl;
	checkDog();
	std::cout << std::endl << std::endl;
	std::cout << "====================================="
			  << " Checking Cat deep copy " 
			  << "=====================================" 
			  << std::endl;
	checkCat();

	return 0;
}
