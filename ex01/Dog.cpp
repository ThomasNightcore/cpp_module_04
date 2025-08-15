/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:58:16 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 22:16:13 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Dog.hpp"

Dog::Dog(void)
{
	m_type = "Dog";
	m_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	m_type = other.m_type;
	m_brain = new Brain(*other.m_brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete m_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << "Dog assignment operator called" << std::endl;
		m_type = other.m_type;
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
	}

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

void Dog::fillIdeas(const int &amount)
{
	std::stringstream strstream;
	for (int i = 0; i < amount && i < Brain::CAPACITY; i++)
	{
		strstream << i;	
		m_brain->addIdea("idea " + strstream.str());
		strstream.clear();
	}
}

void Dog::showIdeas() const
{
	int size = m_brain->getSize();
	for (int i = 0; i < size; i++)
	{
		std::cout << m_brain->getIdeaAt(i) << std::endl;
	}
}
