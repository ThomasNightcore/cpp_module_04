/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:38:51 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 20:53:16 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

const int MateriaSource::INVENTORY_SIZE = 4;

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        m_learnInventory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        AMateria *tmp = other.m_learnInventory[i];
        m_learnInventory[i] = (tmp != NULL) ? tmp->clone() : NULL;
    }
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (m_learnInventory[i] != NULL)
            delete m_learnInventory[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        AMateria *tmp = other.m_learnInventory[i];
        m_learnInventory[i] = (tmp != NULL) ? tmp->clone() : NULL;
    }

    return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (m_learnInventory[i] != NULL)
            continue;

        m_learnInventory[i] = materia;
        break;
    }

    return;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (m_learnInventory[i] == NULL)
            continue;

        if (m_learnInventory[i]->getType() != type)
            continue;

        return m_learnInventory[i]->clone();
    }

    return 0;
}
