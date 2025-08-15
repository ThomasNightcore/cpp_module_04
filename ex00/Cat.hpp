/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:05:46 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 20:25:32 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &other);
	~Cat(void);
	Cat &operator=(const Cat &other);

	void makeSound(void) const;
};

#endif