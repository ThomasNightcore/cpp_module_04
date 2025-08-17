/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:30:45 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 19:37:10 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{

}

Cure::Cure(const Cure &other) : AMateria(other)
{
    m_type = other.m_type;
}

Cure::~Cure(void)
{

}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {

    }

    return *this;
}

AMateria *Cure::clone(void) const
{
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *"
              << std::endl;
}
