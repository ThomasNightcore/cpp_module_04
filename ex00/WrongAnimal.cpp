/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:23:33 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 20:24:13 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
	m_type = "...";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	m_type = other.m_type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		std::cout << "WrongAnimal assignement operator called" << std::endl;
		m_type = other.m_type;
	}

	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal doesn't make a sound..." << std::endl;
}

const std::string &WrongAnimal::getType(void) const 
{
	return m_type;
}

