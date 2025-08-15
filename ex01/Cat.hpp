/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:05:46 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 21:56:45 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *m_brain;
public:
	Cat(void);
	Cat(const Cat &other);
	~Cat(void);
	Cat &operator=(const Cat &other);

	void makeSound(void) const;
	void fillIdeas(const int &amount);
	void showIdeas() const;
};

#endif