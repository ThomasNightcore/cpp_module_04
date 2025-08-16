/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:59:29 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 18:28:53 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	m_type = "...";
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	m_type = other.m_type;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		std::cout << "Animal assignement operator called" << std::endl;
		m_type = other.m_type;
	}

	return *this;
}

const std::string &AAnimal::getType(void) const 
{
	return m_type;
}
