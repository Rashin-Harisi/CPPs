/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:49:44 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 17:13:34 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Constructor from Brain Class called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Copy from Brain Class called" << std::endl;
    
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for(int i = 0; i < 100 ; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Copy operator from Brain Class called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor from Brain Class called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
    ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    return (ideas[i]);
}