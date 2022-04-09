/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:10:49 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 16:10:49 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Noob Form"), _signed(false), _minsigned(50), _minexec(40)
{
    //std::cout << "Default Form Constructor called" << std::endl;
    return;
}

AForm::AForm(std::string name, int minSigned, int minExec)
: _name(name), _signed(false), _minsigned(minSigned), _minexec(minExec)
{
    //std::cout << "Set Form Constructor called" << std::endl;
    try
    {
        if (minSigned < 1 || minExec < 1)
            throw AForm::GradeTooHighException();
        else if (minSigned > 150 || minExec > 150)
            throw AForm::GradeTooLowException();
    }
    catch (GradeTooHighException &high)
    {
        std::cerr << high.what() << std::endl; 
    }
    catch (GradeTooLowException &low)
    {
        std::cerr << low.what() << std::endl;          
    }
}

AForm::AForm(AForm const &src) : _name("Copy"), _minexec(50), _minsigned(80)
{
    //std::cout << "Copy Form Constructor called" << std::endl;
    this->_signed = src._signed;
    return ;
}

AForm::~AForm()
{
    //std::cout << "Destructor Form called" << std::endl;
    return;
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

int    AForm::getMinSigned(void) const
{
    return (this->_minsigned);
}

int    AForm::getMinExec(void) const
{
    return (this->_minexec);
}

bool   AForm::isSigned(void) const
{
    return (this->_signed);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too High exception");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low exception");
}

const char *AForm::FormUnsigned::what(void) const throw()
{
    return ("Form is not signed");
}

void AForm::beSigned(Bureaucrat const& src)
{
    try
    {
        if (src.getGrade() <= this->_minsigned && this->_signed == true)
            std::cout << "The form " << this->_name << "is already signed." << std::endl;  
        else if (src.getGrade() <= this->_minsigned)
        {
            std::cout << "The form " << this->_name << " is now signed." << std::endl;
            this->_signed = true;
        }
        else
            throw Bureaucrat::GradeTooLowException();
    }
    catch (GradeTooLowException& low)
    {
        std::cerr << low.what() << std::endl;
    }

}

void AForm::isExecutable(Bureaucrat const& executor) const
{
    if (this->_signed == false)
    {
        throw AForm::FormUnsigned();
    }
    else if (executor.getGrade() > this->_minexec)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(AForm const &rhs)
{
    this->_signed = rhs._signed;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, AForm const &src)
{
    out << src.getName() << ":\nIs signed ? " << src.isSigned() << std::endl \
        << "Minimun grade to sign: " << src.getMinSigned() << std::endl \
        << "Minimum grade to execute: "<< src.getMinExec() << std::endl;
    return (out);
}