/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:30:14 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 21:18:29 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "Cat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	m_type = other.m_type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		std::cout << "Cat assignment operator called" << std::endl;
		m_type = other.m_type;
	}

	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meoow" << std::endl;
}
