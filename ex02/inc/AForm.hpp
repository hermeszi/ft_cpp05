/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/25 14:41:17 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
class Bureaucrat;

class Form
{
private:
	std::string const       _name;
	bool                    _signed;
	unsigned int const      _gradeToSign;
	unsigned int const      _gradeToEx;

	static unsigned int gradeValid(unsigned int grade);

public:
	Form();
	Form(std::string name, unsigned int gradeToSign, unsigned int gradeToEx);
	virtual ~Form() {};
	Form(const Form& copy);
	Form& operator=(const Form& other);

	std::string     getName() const;
	bool            getSigned() const;
	unsigned int    getGradeToSign() const;
	unsigned int    getGradeToEx() const;

	void            beSigned(const Bureaucrat& bureaucrat);
	void 			execute(Bureaucrat const & executor) const = 0;

	struct GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw() {return "Grade is too HIGH";}
	};
	struct GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw() {return "Grade is too LOW";}
	};
};

std::ostream& operator<< (std::ostream& os, const Form& f);

#endif
