/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:36:31 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 21:36:31 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 72, 45), _target("Pomme solitaire")
{
    // std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 72, 45), _target(target)
{
    // std::cout << "ShrubberyCreationForm Target constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src.getName(), src.getMinSigned(), src.getMinExec()), _target(src._target)
{
    // std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::ft_tree(const Bureaucrat &executor) const
{
    std::ifstream ifs(this->_target + "_shrubbery");
    if (ifs.fail())
        ifs.close();
    else
    {
        ifs.close();
        std::cout << this->_target << " doesn't have room for a shrubbery." << std::endl;
        return;
    }

    std::ofstream ofs(this->_target + "_shrubbery");
    if (ofs.fail())
    {
        ofs.close();
        std::cout << this->_target << " doesn't have room for a shrubbery." << std::endl;
        return;
    }
    else
    {
        ofs << "This is a tree: | " << std::endl;
        ofs.close();
    }
    std::cout << "A shrubbery tree has been planted at " << this->_target << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
    this->ft_tree(executor);
}

ShrubberyCreationForm ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    (void)rhs;
    return (*this);
}