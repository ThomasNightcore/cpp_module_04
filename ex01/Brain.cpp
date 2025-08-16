/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:57:03 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 18:55:21 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

const int Brain::CAPACITY = 100;

Brain::Brain(void)
{
	m_size = 0;
	for (int i = 0; i < CAPACITY; i++)
	{
		m_ideas[i] = "";
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < CAPACITY; i++)
	{
		std::string idea = other.m_ideas[i];
		m_ideas[i] = idea;
	}
	m_size = other.m_size;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		std::cout << "Brain assignment oparator called" << std::endl;
		for (int i = 0; i < CAPACITY; i++)
		{
			std::string idea = other.m_ideas[i];
			this->m_ideas[i] = idea;
		}
		this->m_size = other.m_size;
	}

	return *this;
}

std::string Brain::getIdeaAt(const int &index) const
{
	if (index < 0 || index >= CAPACITY)
		return "Brain is too small!";

	return m_ideas[index];
}

bool Brain::addIdea(const std::string &idea)
{
	if (m_size >= CAPACITY)
		return false;

	m_ideas[m_size++] = idea;
	return true;
}

const int &Brain::getSize(void) const 
{
	return m_size;
}
