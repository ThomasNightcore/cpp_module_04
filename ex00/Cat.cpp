/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:09:45 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 21:18:29 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	m_type = other.m_type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << "Cat assignment operator called" << std::endl;
		m_type = other.m_type;
	}

	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meoow" << std::endl;
}
