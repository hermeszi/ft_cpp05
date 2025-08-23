/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/23 22:54:59 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

using std::string;
using std::endl;
using std::cout;

Form::Form()
:   _name("Unnamed"),
	_signed(0),
	_gradeToSign(1),
	_gradeToEx(1)

{
	cout << "Form DEFAULT constructor called" << endl;
}

Form::Form(string name, unsigned int gradeToSign, unsigned int gradeToEx) 
:   _name(name),
	_signed(0),
	_gradeToSign(gradeValid(gradeToSign)),
	_gradeToEx(gradeValid(gradeToEx))
{
	cout << "Form constructor called for: " << _name  << " Grade to sign: " << _gradeToSign << "Grade to Execute:" << _gradeToEx << endl;
}

Form::Form	(const Form& copy) 
:   _name(copy.getName()),
	_signed(copy.getSigned()),
	_gradeToSign(gradeValid(copy.getGradeToSign())), 
	_gradeToEx(gradeValid(copy.getGradeToEx()))
{
	//cout << "Form Copy-Constructor called" << endl;
}

Form& Form::operator= (const Form& other)
{
	//cout << "Form Copy-Ass = called" << endl;
	if (this != &other)
	{
		this->_signed = other.getSigned();
	}
	return (*this);
}

Form::~Form()
{
	cout << "Form destructor: " << _name << endl;
}

string	Form::getName() const
{
	return (this->_name);	
}

unsigned int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

unsigned int	Form::getGradeToEx() const
{
	return (this->_gradeToEx);
}

bool    Form::getSigned() const
{
	return (this->_signed);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_signed == 0)
	{
		if (bureaucrat.getGrade() <= this->getGradeToSign())
		{
			_signed = 1;
		}
		else
		{
			throw GradeTooLowException();
		}
	}
}

unsigned int Form::gradeValid(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

std::ostream& operator<< (std::ostream& os, const Form& Form)
{
	os << Form.getName() << "\nGrade to Sign: " << Form.getGradeToSign() << "\nGrade to Execute: " << Form.getGradeToEx() << "\nSigned:" << Form.getSigned() << "." << endl;
	return (os);
}
