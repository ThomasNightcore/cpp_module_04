/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:43:11 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 20:03:29 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

const int Character::INVENTORY_SIZE = 4;

Character::Character(void)
{
    m_name = "Default Character";
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        m_inventory[i] = NULL;
    }
}

Character::Character(const std::string &name)
{
    m_name = name;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        m_inventory[i] = NULL;
    }
}

Character::Character(const Character& other)
{
    m_name = other.m_name;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        AMateria *mat = other.m_inventory[i];
        m_inventory[i] = (mat != NULL) ? mat->clone() : NULL;
    }
}

Character::~Character(void)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (m_inventory[i] != NULL)
            delete m_inventory[i];
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        m_name = other.m_name;
        for (int i = 0; i < INVENTORY_SIZE; i++)
        {
            AMateria *mat = other.m_inventory[i];
            m_inventory[i] = (mat != NULL) ? mat->clone() : NULL;
        }
    }

    return *this;
}

const std::string &Character::getName(void) const
{
    return m_name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (m_inventory[i] == NULL)
            continue;

        m_inventory[i] = m;
        break;
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= INVENTORY_SIZE)
        return;
    
    m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= INVENTORY_SIZE)
        return;

    m_inventory[idx]->use(target);
}
