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
    //std::cout << "Default Constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    //std::cout << "Set Constructor called" << std::endl;
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

Bureaucrat::Bureaucrat(Bureaucrat const& src): _name("Copy")
{
    //std::cout << "Copy Constructor called" << std::endl;
    this->_grade = src._grade;
    return ;
}

Bureaucrat::~Bureaucrat()
{
    //std::cout << "Destructor called" << std::endl;
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

void    Bureaucrat::plusGrade()
{
    try
    {
        if (this->_grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->_grade--;
    }
    catch (GradeTooHighException& high)
    {
        std::cerr << high.what() << std::endl; 
    }
}

void    Bureaucrat::minusGrade()
{
    try
    {
        if (this->_grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->_grade++;
    }
    catch (GradeTooLowException& low)
    {
        std::cerr << low.what() << std::endl; 
    }
}

void    Bureaucrat::signForm(AForm &Form)
{
    try
    {
        Form.beSigned(*this);
    }
    catch(GradeTooLowException& low)
    {
        std::cout << this->_name << " couldn't sign " << Form.getName() << " because Grade is too low" << std::endl;
        return ;
    }
    
}

void	Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        form.isExecutableBureaucrat(*this);
    }
    catch (NotExecutable &e)
    {
        std::cerr << this->getName() << " " << e.what() << std::endl;
        return;
    }
    std::cout << this->_name << " executed " << form.getName() << std::endl;
}

const	char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too High exception");
}

const	char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low exception");
}

const char *Bureaucrat::NotExecutable::what(void) const throw()
{
    return ("Form is not executable");
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& rhs)
{
    this->_grade = rhs._grade;
    return (*this);
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const& src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return (out);
}