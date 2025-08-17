/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:56:13 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 20:01:54 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(const std::string &type)
{
    m_type = type;
}

AMateria::AMateria(const AMateria &other)
{
    m_type = other.m_type;
}

AMateria::~AMateria(void)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        // what to do here??!
        // subject is not very clear...
        // apperently the type should not be assigned. Makes sense when the types do not match...
        // so do nothing here and then only check in the derived class...
        // I guess it doesn't make any sense at all to have an assignment operator here at all
    }

    return *this;
}

const std::string &AMateria::getType(void) const { return m_type; }

void AMateria::use(ICharacter &target)
{
    std::cout << "* Materia at " << target.getName() << " *" << std::endl;
}
