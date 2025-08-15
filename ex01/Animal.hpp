/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:54:32 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 20:25:22 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class Animal
{
protected:
	std::string m_type;
public:
	Animal(void);
	Animal(const Animal &other);
	virtual ~Animal(void);
	Animal &operator=(const Animal &other);

	virtual void makeSound(void) const;
	const std::string &getType(void) const;
};

#endif
