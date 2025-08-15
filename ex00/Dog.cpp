/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:58:16 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 20:12:39 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void)
{
	m_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	m_type = other.m_type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << "Dog assignment operator called" << std::endl;
		m_type = other.m_type;
	}

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
