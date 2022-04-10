/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:41:02 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/10 11:41:02 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
    this->Form[0] = "shrubbery creation";
    this->Form[1] = "robotomy request";
    this->Form[2] = "presidential pardon";
    return ;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
    return;
}

Intern::Intern(Intern const& src)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    this->Form[0] = src.Form[0];
    this->Form[1] = src.Form[1];
    this->Form[2] = src.Form[2];
    return ;
}

Intern& Intern::operator=(Intern const& rhs)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    this->Form[0] = rhs.Form[0];
    this->Form[1] = rhs.Form[1];
    this->Form[2] = rhs.Form[2];
    return (*this);
}

AForm* Intern::makeForm(std::string FormName, std::string target) const
{
    int i;

    i = 0;
    while (i < 3 && FormName != this->Form[i])
        i++;
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << FormName << std::endl;
        return (new ShrubberyCreationForm(target));
    case 1:
        std::cout << "Intern creates " << FormName << std::endl;
        return (new RobotomyRequestForm(target));
    case 2:
        std::cout << "Intern creates " << FormName << std::endl;
        return (new PresidentialPardonForm(target));
    default:
        std::cout << "The Form: " << FormName << " doesn't exist." << std::endl;
        return (NULL);
    }
}