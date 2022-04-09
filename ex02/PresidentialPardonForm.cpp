/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:10:45 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 18:10:45 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("Pomme solitaire")
{
    //std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    //std::cout << "PresidentialPardonForm Target constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
: AForm(src.getName(), src.getMinSigned(), src.getMinExec()), _target(src._target)
{
    //std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    //std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        this->isExecutable(executor);
    }
    catch(FormUnsigned& e)
    {
        std::cerr << this->getName() << " " << e.what() << std::endl;
        return ;
    }
    catch(GradeTooLowException& e)
    {
        std::cerr << executor.getName() << " " << e.what() << std::endl;
        return ;
    }
    std::cout << this->_target << " has been pardonned by Zaphod Beeblerox." << std::endl;
}

PresidentialPardonForm PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
    (void)rhs;
    return (*this);
}