/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:09:45 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 19:32:18 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <sstream>

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "Cat";
	m_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	m_type = other.m_type;
	m_brain = new Brain(*other.m_brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete m_brain;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << "Cat assignment operator called" << std::endl;
		m_type = other.m_type;
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
	}

	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meoow" << std::endl;
}

void Cat::fillIdeas(const int &amount)
{
	std::stringstream strstream;
	for (int i = 0; i < amount && i < Brain::CAPACITY; i++)
	{
		strstream << i;	
		m_brain->addIdea("idea " + strstream.str());
		strstream.str("");
	}
}

void Cat::showIdeas() const
{
	int size = m_brain->getSize();
	if (size == 0)
	{
		std::cout << "This cat has no thoughts" << std::endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << m_brain->getIdeaAt(i) << std::endl;
	}
}
