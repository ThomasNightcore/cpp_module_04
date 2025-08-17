/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:36:50 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/17 20:34:57 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __I_MATERIA_SOURCE_HPP__
# define __I_MATERIA_SOURCE_HPP__

# include "AMateria.hpp"
# include <string>

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
