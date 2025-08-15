/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:51:01 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 22:21:05 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

static void checkDog(void)
{
	Dog *guy1 = new Dog();
	guy1->fillIdeas(3);
	
	std::cout << std::endl;
	std::cout << "dog 1 ideas:" << std::endl;
	guy1->showIdeas();

	std::cout << std::endl;
	Dog *guy2 = new Dog(*guy1);

	std::cout << std::endl;
	std::cout << "dog 2 ideas:" << std::endl;
	guy2->showIdeas();

	delete guy1;

	std::cout << std::endl << "dog 2 ideas:" << std::endl;
	guy2->showIdeas();
	std::cout << std::endl;

	delete guy2;

}

static void checkCat(void)
{
	Cat *guy1 = new Cat();
	guy1->fillIdeas(3);
	
	std::cout << std::endl;
	std::cout << "cat 1 ideas:" << std::endl;
	guy1->showIdeas();

	std::cout << std::endl;
	Cat *guy2 = new Cat(*guy1);

	std::cout << std::endl;
	std::cout << "cat 2 ideas:" << std::endl;
	guy2->showIdeas();

	delete guy1;

	std::cout << std::endl << "cat 2 ideas:" << std::endl;
	guy2->showIdeas();
	std::cout << std::endl;

	std::cout << "========== Checking CAT assignement ==========" << std::endl;
	Cat *guy3 = new Cat();
	std::cout << std::endl << "cat 3 ideas:" << std::endl;
	guy3->showIdeas();
	guy3 = guy2;

	delete guy2;

	std::cout << std::endl;
	std::cout << std::endl << "cat 3 ideas:" << std::endl;
	guy3->showIdeas();

	//delete guy3;
}

int main()
{
	std::cout << "=============== Checking Dog deep copy ===============" << std::endl;
	checkDog();
	std::cout << std::endl;
	std::cout << "=============== Checking Cat deep copy ===============" << std::endl;
	checkCat();



	return 0;
}
