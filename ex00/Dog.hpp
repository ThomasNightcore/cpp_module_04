/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:07:37 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 20:25:35 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &other);
	~Dog(void);
	Dog &operator=(const Dog &other);

	void makeSound(void) const;
};

#endif