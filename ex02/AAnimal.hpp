/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:54:32 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/16 21:27:59 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class AAnimal
{
protected:
	std::string m_type;
public:
	AAnimal(void);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal(void);
	AAnimal &operator=(const AAnimal &other);

	virtual void makeSound(void) const = 0;
	const std::string &getType(void) const;
};

#endif
