/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:09:45 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 23:09:49 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <sstream>

Cat::Cat(void)
{
	m_type = "Cat";
	m_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	m_type = other.m_type;
	m_brain = new Brain(*other.m_brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete m_brain;
	std::cout << "Cat destructor called" << std::endl;
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
		strstream.clear();
	}
}

void Cat::showIdeas() const
{
	int size = m_brain->getSize();
	for (int i = 0; i < size; i++)
	{
		std::cout << m_brain->getIdeaAt(i) << std::endl;
	}
}
