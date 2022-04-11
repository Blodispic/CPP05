/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:37:08 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 21:37:08 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string const _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    void ft_tree(const Bureaucrat &executor) const;
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;

    ShrubberyCreationForm operator=(ShrubberyCreationForm const &rhs);
};
#endif