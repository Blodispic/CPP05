/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:31:32 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 21:31:32 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class RobotomyRequestForm : public AForm
{
private:
    std::string const _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;

    RobotomyRequestForm operator=(RobotomyRequestForm const &rhs);
};
#endif