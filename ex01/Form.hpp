/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:01:43 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/09 15:01:43 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _minsigned;
        int const _minexec;


    public:
        Form();
        Form(std::string name, int minSigned, int minExec);
        Form(Form const& src);
        ~Form();

        std::string	getName() const;
        int         getMinSigned(void) const;
        int         getMinExec(void) const;
        bool        isSigned(void) const;
        void        beSigned(Bureaucrat const& src);
        Form & operator=(Form const& rhs);

    class GradeTooHighException : public std::exception
	{
		public:
			virtual const	char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const	char* what(void) const throw();
	};
};


#endif