/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:33:36 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 19:30:00 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(const Cure &other);
    ~Cure(void);
    Cure &operator=(const Cure &other);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};

#endif
