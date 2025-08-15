/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:07:37 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 21:56:50 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *m_brain;
public:
	Dog(void);
	Dog(const Dog &other);
	~Dog(void);
	Dog &operator=(const Dog &other);

	void makeSound(void) const;
	void fillIdeas(const int &amount);
	void showIdeas() const;
};

#endif