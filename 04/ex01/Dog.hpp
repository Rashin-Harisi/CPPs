/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:46:29 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 17:28:21 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();
    void makeSound() const;
    void setIdea(int i, std::string idea);
    std::string getIdea(int i) const;

private:
    Brain* brain;
};

#endif // DOG_HPP