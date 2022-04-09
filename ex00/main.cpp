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

int main(void)
{
    Bureaucrat max("Max", 1);
    Bureaucrat toomax("Max2", 1500);
    Bureaucrat copy(max);

    std::cout << max << std::endl;
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


    return (0);
}