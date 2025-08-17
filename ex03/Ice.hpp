/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:33:42 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 19:37:10 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice(void);
    Ice(const Ice &other);
    ~Ice(void);
    Ice &operator=(const Ice &other);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};

#endif
