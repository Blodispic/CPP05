/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:16:04 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 13:16:04 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    Bureaucrat max("Max", 1);
    Bureaucrat Noobureacrat("Noob Bureaucrat", 150);
    Bureaucrat copy(max);

    PresidentialPardonForm form1("Lolipop");
    PresidentialPardonForm form2;
    form2 = form1;

    ShrubberyCreationForm   tree1("BIgTree");

    RobotomyRequestForm     robot1("Robot");

    std::cout << form1 << std::endl;
    max.executeForm(form1);
    form1.execute(max);
    form1.execute(Noobureacrat);
    Noobureacrat.signForm(form1);
    max.signForm(form1);
    form1.execute(max);
    form1.execute(Noobureacrat);
    form2.execute(max);
    max.executeForm(form1);
    Noobureacrat.executeForm(form1);
    max.executeForm(tree1);
    max.signForm(tree1);
    max.executeForm(tree1);
    Noobureacrat.executeForm(tree1);
    max.executeForm(robot1);
    max.signForm(robot1);
    for (int i = 0; i < 10; i++)
        max.executeForm(robot1);

    return (0);
}