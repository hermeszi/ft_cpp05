/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/24 21:19:56 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

using std::string;
using std::endl;
using std::cout;

AForm::AForm()
:   _name("Unnamed"),
	_target(""),
	_signed(false),
	_gradeToSign(1),
	_gradeToEx(1)
{
	cout << "AForm DEFAULT constructor called" << endl;
}

AForm::AForm(string name, string target, unsigned int gradeToSign, unsigned int gradeToEx) 
:   _name(name),
	_target(target),
	_signed(false),
	_gradeToSign(gradeValid(gradeToSign)),
	_gradeToEx(gradeValid(gradeToEx))
{
	cout << "AForm constructor called for: " 
		 << _name
		 << "\n    Grade to sign   : "
		 << _gradeToSign
		 << "\n    Grade to Execute: " 
		 << _gradeToEx
		 << endl;
}

AForm::AForm	(const AForm& copy) 
:   _name(copy.getName()),
	_target(copy.getTarget()),
	_signed(copy.getSigned()),
	_gradeToSign(gradeValid(copy.getGradeToSign())), 
	_gradeToEx(gradeValid(copy.getGradeToEx()))
{
	//cout << "AForm Copy-Constructor called" << endl;
}

AForm& AForm::operator= (const AForm& other)
{
	//cout << "AForm Copy-Ass = called" << endl;
	if (this != &other)
	{
		this->_target = other.getTarget();
	}
	return (*this);
}

string	AForm::getName() const
{
	return (this->_name);	
}

string AForm::getTarget() const
{
	return (this->_target);
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

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	
	if (executor.getGrade() > _gradeToEx)
		throw AForm::GradeTooLowException();
		
	this->doExecute();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os	<< " ==== Form name: "
		<< f.getName() << " ====\n"
		<< "  Target : " << f.getTarget()
		<< "\n  Signed : " << std::boolalpha << static_cast<bool>(f.getSigned()) << "\n"
		<< "  sign grade: " << f.getGradeToSign() << "\n"
		<< "  exec grade: " << f.getGradeToEx()
		<< "\n ================="
		<< endl;
	return (os);
}

