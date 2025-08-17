/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:38:38 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 20:03:26 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include "ICharacter.hpp" 

class Character : public ICharacter
{
private:
    std::string m_name;
    AMateria *m_inventory[4];

    static const int INVENTORY_SIZE;

    Character(void);

public:
    Character(const std::string &name);
    Character(const Character &other);
    ~Character(void);
    Character &operator=(const Character &other);

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif
