/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:33:00 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 11:33:00 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Noob Bureaucrat"), _grade(83)
{
    std::cout << "Default Constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->_grade = grade;
    }
    catch (GradeTooHighException& high)
    {
        std::cerr << high.what() << std::endl;
        this->_grade = 1;
    }
    catch (GradeTooLowException& low)
    {
        std::cerr << low.what() << std::endl;
        this->_grade = 150;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
    return ;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int    Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

std::string    Bureaucrat::getName(void) const
{
    return (this->_name);
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& rhs)
{
    *this = rhs;
    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const
{
    return ("Grade is too high exception");
}

const char* Bureaucrat::GradeTooLowException::what() const
{
    return ("Grade is too low exception");
}