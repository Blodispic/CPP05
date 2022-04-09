/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:59:32 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 17:59:32 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class PresidentialPardonForm: public AForm
{
private:
    std::string const _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const& src);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;

    PresidentialPardonForm operator=(PresidentialPardonForm const& rhs);
};
#endif