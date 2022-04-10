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
    this->FormExec[0] = &Intern::ShrubberyForm;
    this->FormExec[1] = &Intern::RobotForm;
    this->FormExec[2] = &Intern::PresidentForm;
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
    this->FormExec[0] = src.FormExec[0];
    this->FormExec[1] = src.FormExec[1];
    this->FormExec[2] = src.FormExec[2];
    return ;
}

Intern& Intern::operator=(Intern const& rhs)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    this->Form[0] = rhs.Form[0];
    this->Form[1] = rhs.Form[1];
    this->Form[2] = rhs.Form[2];
    this->FormExec[0] = rhs.FormExec[0];
    this->FormExec[1] = rhs.FormExec[1];
    this->FormExec[2] = rhs.FormExec[2];
    return (*this);
}

AForm* Intern::PresidentForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::RobotForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::ShrubberyForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string FormName, std::string target)
{
    int i;

    i = 0;
    while (i < 3 && FormName != this->Form[i])
        i++;
    if (i >= 3)
    {
        std::cout << "The Form: " << FormName << " doesn't exist." << std::endl;
        return (NULL);
    }
    std::cout << "Intern creates " << FormName << std::endl;
    return ((this->*FormExec[i])(target));
}