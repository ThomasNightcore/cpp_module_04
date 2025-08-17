/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:38:09 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 20:51:30 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIA_SOURCE_HPP__
# define __MATERIA_SOURCE_HPP__

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
private:
    AMateria *m_learnInventory[4];

    static const int INVENTORY_SIZE;
public:
    MateriaSource(void);
    MateriaSource(const MateriaSource &other);
    ~MateriaSource(void);
    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria *materia);
    AMateria* createMateria(std::string const &type);
};

#endif

