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

class AForm
{
    private:
        std::string const _name;
        bool _signed;
        int const _minsigned;
        int const _minexec;


    public:
        AForm();
        AForm(std::string name, int minSigned, int minExec);
        AForm(AForm const& src);
        virtual ~AForm();

        std::string	getName() const;
        int         getMinSigned(void) const;
        int         getMinExec(void) const;
        bool        isSigned(void) const;
        void        beSigned(Bureaucrat const& src);
        AForm&      operator=(AForm const& rhs);

        void        isExecutable(Bureaucrat const& executor) const;
        void        isExecutableBureaucrat(Bureaucrat const &executor) const;
        virtual void execute(Bureaucrat const &executor) const = 0;

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

    class FormUnsigned : public std::exception
    {
    public:
        virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif