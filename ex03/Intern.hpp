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
public:
    Intern();
    Intern(Intern const& src);
    ~Intern();
    Intern&  operator=(Intern const& rhs);

    AForm*   makeForm(std::string FormName, std::string target) const;
};

#endif