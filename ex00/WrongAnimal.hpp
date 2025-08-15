/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:22:04 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 20:22:56 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_ANIMAL_HPP__
# define __WRONG_ANIMAL_HPP__

# include <string>

class WrongAnimal
{
protected:
	std::string m_type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal(void);
	WrongAnimal &operator=(const WrongAnimal &other);

	void makeSound(void) const;
	const std::string &getType(void) const;
};

#endif