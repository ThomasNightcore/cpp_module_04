/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:13:01 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 19:35:25 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
    // do something here
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    m_type = other.m_type;
}

Ice::~Ice(void)
{

}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {

    }

    return *this;
}

AMateria *Ice::clone(void) const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}
