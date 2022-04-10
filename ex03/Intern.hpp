/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:37:23 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/10 11:37:23 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CPP
#define INTERN_CPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp" 
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    std::string Form[3];
    AForm* (Intern::*FormExec[3])(std::string target);
public:
    Intern();
    Intern(Intern const& src);
    ~Intern();
    Intern&  operator=(Intern const& rhs);
    AForm*  PresidentForm(std::string target);
    AForm*  RobotForm(std::string target);
    AForm*  ShrubberyForm(std::string target);

    AForm*   makeForm(std::string FormName, std::string target);
};

#endif