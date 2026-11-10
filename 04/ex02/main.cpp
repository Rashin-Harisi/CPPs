/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:48:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 18:51:59 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    {
        Dog original;
    
        original.setIdea(0, "Find a bone");
        std::cout << "original : " << original.getIdea(0) << std::endl;
    
        std::cout << "Copy operator= \n";
        Dog copied(original);
        std::cout << "copied : " << copied.getIdea(0) << std::endl;
        copied.setIdea(0, "Take a nap");
        std::cout << "copied : " << copied.getIdea(0) << std::endl;
 
        std::cout << "Copy \n";
        Dog assigned;
        assigned = original;
        std::cout << "original : " << original.getIdea(0) << std::endl;
        std::cout << "assigned : " << assigned.getIdea(0) << std::endl;
    }
    
    {
        Animal* animals[10];
        for (int i = 0; i < 5; i++)
            animals[i] = new Dog();
        for (int i = 5; i < 10; i++)
            animals[i] = new Cat();

        for (int i = 0; i < 10 ; i++)
        {
            animals[i]->makeSound();
        }
        for (int i = 0; i < 10 ; i++)
        {
            delete animals[i];
        }
    }
    return (0);
}