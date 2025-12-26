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

#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
	std::string const       _name;
	std::string 			_target;
	bool                    _signed;
	unsigned int const      _gradeToSign;
	unsigned int const      _gradeToEx;

	static unsigned int gradeValid(unsigned int grade);

public:
	AForm();
	AForm(std::string name, std::string target, unsigned int gradeToSign, unsigned int gradeToEx);
	virtual ~AForm() {};
	AForm(const AForm& copy);
	AForm& operator=(const AForm& other);

	std::string     getName() const;
	std::string		getTarget() const;
	bool            getSigned() const;
	unsigned int    getGradeToSign() const;
	unsigned int    getGradeToEx() const;

	void            beSigned(const Bureaucrat& bureaucrat);
	void 			execute(Bureaucrat const & executor) const;
	virtual void	doExecute() const = 0;

	struct GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw() {return "Grade is too HIGH";}
	};
	struct GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw() {return "Grade is too LOW";}
	};
	struct FormNotSignedException : public std::runtime_error
	{
		FormNotSignedException(): std::runtime_error("Form is not signed") {}
	};
};

std::ostream& operator<< (std::ostream& os, const AForm& f);

#endif
