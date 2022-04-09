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
#include "Form.hpp"

int main(void)
{
    Bureaucrat max("Max", 1);
    Bureaucrat toomax("Max2", 50);
    Bureaucrat copy(max);
    Bureaucrat copyassignment;
    copyassignment = copy;

    Form    form1("Big form", 50, 40);
    Form    form2;
    Form    form3(form2);

    form2 = form1;
    
    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << std::endl << max << std::endl;
    std::cout << toomax << std::endl;
    std::cout << copy << std::endl << std::endl;
    max.minusGrade();
    std::cout << max << std::endl;
    max.plusGrade();
    std::cout << max << std::endl;
    max.plusGrade();
    std::cout << max << std::endl;

    toomax.minusGrade();
    std::cout << toomax << std::endl;
    toomax.minusGrade();
    std::cout << toomax << std::endl;
    toomax.plusGrade();
    std::cout << toomax << std::endl;

    max.signForm(form1);
    max.signForm(form1);
    toomax.signForm(form2);
    std::cout << toomax << std::endl;
    toomax.plusGrade();
    std::cout << toomax << std::endl;
    toomax.plusGrade();
    std::cout << toomax << std::endl;
    toomax.signForm(form2);
    toomax.signForm(form2);

    std::cout << copyassignment << std::endl;

    return (0);
}