/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:32:16 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 21:32:16 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Pomme solitaire")
{
    // std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    // std::cout << "RobotomyRequestForm Target constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
    : AForm(src.getName(), src.getMinSigned(), src.getMinExec()), _target(src._target)
{
    // std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try
    {
        this->isExecutable(executor);
    }
    catch (FormUnsigned &e)
    {
        std::cerr << this->getName() << " " << e.what() << std::endl;
        return;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << executor.getName() << " " << e.what() << std::endl;
        return;
    }
        std::cout << "Brrrrrrrrrrrrrrrrr   Directed by mberrrrrn" << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->_target << " get Robotomised" << std::endl;
    else
        std::cout << "Operation failed" << std::endl;
}

RobotomyRequestForm RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    (void)rhs;
    return (*this);
}