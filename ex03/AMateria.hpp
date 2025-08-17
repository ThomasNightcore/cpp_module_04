/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:33:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 20:03:58 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_MATERIA_HPP__
# define __A_MATERIA_HPP__

# include <string>
# include "ICharacter.hpp"
class ICharacter;

class AMateria
{
protected:
    std::string m_type;
public:
    AMateria(const std::string &type);
    AMateria(const AMateria &other);
    virtual ~AMateria(void);
    AMateria &operator=(const AMateria &other);

    const std::string &getType(void) const;
    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter &target);
};

#endif
