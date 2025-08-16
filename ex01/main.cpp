/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:51:01 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 21:14:12 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

static void checkDog(void)
{
	std::cout << "====================================="
			  << " Checking Dog deep copy " 
			  << "=====================================" 
			  << std::endl;
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
	std::cout << "====================================="
			  << " Checking Cat deep copy " 
			  << "=====================================" 
			  << std::endl;
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

static void testSubjectArray(void)
{
	const int arr_size = 8;
	Animal *arr[8]; 

	std::cout << "=============================="
			  << " Creating " << arr_size << " Animals "
			  << "==============================" << std::endl;
	// Create array objects
	for (int i = 0; i < arr_size; i++)
	{
		if (i & 0b1)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
		std::cout << " *  creating animal at index [" << i << "]. Type is: \'" << arr[i]->getType() << '\'' << std::endl;
	}

	std::cout << std::endl
			  << "=============================="
			  << " Calling virtual method makeSound() for each animal "
			  << "==============================" << std::endl;
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << "Animal [" << i << "] with type [" 
				  << arr[i]->getType() << "] makes sound: ";
		arr[i]->makeSound();
	}

	std::cout << std::endl
			  << "=============================="
			  << " Deleting entries in array "
			  << "==============================" << std::endl;
	// Delete array objects
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << " * deleting animal at index [" << i << "]. Type is: \'" << arr[i]->getType() << '\'' << std::endl;
		delete arr[i];
	}
}

int main()
{
	std::cout << "Enter which test cases you want to execute:" << std::endl
			  << " * (1) Run deepcopy copy constructor and assignment operator tests" << std::endl
			  << " * (2) Run subject array test" << std::endl
			  << " * (3) Run both" << std::endl;

	char input;
	std::cin >> std::ws >> input;
	bool should_test_custom = (input == '3') ? true : ((input == '1') ? true : false);
	bool should_test_subject = (input == '3') ? true : ((input == '2') ? true : false);

	if (!(should_test_custom || should_test_subject))
		std::cout << "Invalid input! Exiting." << std::endl;
	if (should_test_custom)
	{
		std::cout << " *** Executing custom deep copy tests *** " << std::endl; 
		checkDog();
		std::cout << std::endl << std::endl;
		checkCat();
	}
	if (should_test_custom && should_test_subject)
		std::cout << std::endl << std::endl;
	if (should_test_subject)
	{
		std::cout << " *** Executing subject array tests *** " << std::endl; 
		testSubjectArray();
	}

	return 0;
}
