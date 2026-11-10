/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:49:48 by rabdolho          #+#    #+#             */
/*   Updated: 2026/11/10 17:13:46 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "string"


class Brain
{
public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();
    void setIdea(int i, std::string idea);
    std::string getIdea(int i) const;

private:
    std::string ideas[100];
    
};

#endif // BRAIN_HPP