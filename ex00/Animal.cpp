/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:59:29 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 21:18:23 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	m_type = "...";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	m_type = other.m_type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		std::cout << "Animal assignement operator called" << std::endl;
		m_type = other.m_type;
	}

	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal doesn't make a sound..." << std::endl;
}

const std::string &Animal::getType(void) const 
{
	return m_type;
}
