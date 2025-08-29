/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/29 20:52:10 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

using std::string;
using std::endl;
using std::cout;

AForm::Form()
:   _name("Unnamed"),
	_signed(false),
	_gradeToSign(1),
	_gradeToEx(1)

{
	cout << "Form DEFAULT constructor called" << endl;
}

AForm::Form(string name, unsigned int gradeToSign, unsigned int gradeToEx) 
:   _name(name),
	_signed(false),
	_gradeToSign(gradeValid(gradeToSign)),
	_gradeToEx(gradeValid(gradeToEx))
{
	cout << "Form constructor called for: " 
		 << _name
		 << "\n    Grade to sign   : "
		 << _gradeToSign
		 << "\n    Grade to Execute: " 
		 << _gradeToEx
		 << endl;
}

AForm::Form	(const AForm& copy) 
:   _name(copy.getName()),
	_signed(copy.getSigned()),
	_gradeToSign(gradeValid(copy.getGradeToSign())), 
	_gradeToEx(gradeValid(copy.getGradeToEx()))
{
	//cout << "Form Copy-Constructor called" << endl;
}

AForm& Form::operator= (const AForm& other)
{
	//cout << "Form Copy-Ass = called" << endl;
	if (this != &other)
	{
		this->_signed = other.getSigned();
	}
	return (*this);
}

AForm::~Form()
{
	cout << "Form destructor: " << _name << endl;
}

string	AForm::getName() const
{
	return (this->_name);	
}

unsigned int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

unsigned int	AForm::getGradeToEx() const
{
	return (this->_gradeToEx);
}

bool    AForm::getSigned() const
{
	return (this->_signed);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_signed == false)
	{
		if (bureaucrat.getGrade() <= this->getGradeToSign())
		{
			_signed = true;
		}
		else
		{
			throw GradeTooLowException();
		}
	}
}

unsigned int AForm::gradeValid(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os	<< f.getName()
		<< " (signed: " << std::boolalpha << static_cast<bool>(f.getSigned()) << ")\n"
		<< "  sign grade: " << f.getGradeToSign() << "\n"
		<< "  exec grade: " << f.getGradeToEx()
		<< "\n";
	return (os);
}

