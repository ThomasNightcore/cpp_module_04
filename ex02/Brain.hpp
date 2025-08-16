/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:57:18 by tluegham          #+#    #+#             */
/*   Updated: 2025/08/15 21:59:26 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>

class Brain
{
private:
	int m_size;
	std::string m_ideas[100];
public:
	Brain(void);
	Brain(const Brain &other);
	~Brain(void);
	Brain &operator=(const Brain &other);

	static const int CAPACITY;

	const int &getSize(void) const;
	bool addIdea(const std::string &idea);
	std::string getIdeaAt(const int &index) const;
};

#endif