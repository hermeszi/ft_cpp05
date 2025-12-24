/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/24 21:43:30 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

using std::string;
using std::endl;
using std::cout;

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
	cout << "Bureaucrat DEFAULT constructor called" << endl;
}

Bureaucrat::Bureaucrat(string name, unsigned int grade) : _name(name), _grade(gradeValid(grade))
{
	cout << "Bureaucrat constructor called for: "
		 << _name
		 << "\n    Grade: " 
		 << _grade
		 << endl;
}

Bureaucrat::Bureaucrat	(const Bureaucrat& copy) : _name(copy.getName()), _grade(gradeValid(copy.getGrade()))
{
	//cout << "Bureaucrat Copy-Constructor called" << endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
	//cout << "Bureaucrat Copy-Ass = called" << endl;
	if (this != &other)
	{
		this->_grade = gradeValid(other.getGrade());
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructor: " 
		 << _name 
		 << endl;
}

string	Bureaucrat::getName() const
{
	return (this->_name);	
}

unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	_grade = gradeValid(--_grade);
}
void Bureaucrat::decrementGrade()
{
	_grade = gradeValid(++_grade);
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		cout << this->getName() << " signed " << form.getName() << endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		cout << this->getName() 
			 << " couldn't sign " 
			 << form.getName() 
			 << " because " 
			 << e.what() 
			 << "." 
			 << endl;
	}
}

unsigned int Bureaucrat::gradeValid(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}
void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		cout << this->getName() << " executed " <<  form.getName() << "." << std::endl;
	}
	catch (const AForm::FormNotSignedException& e){
        std::cout << this->getName() <<" cannot execute " << form.getName()  << " because: " << e.what() << "\nCheck Form is signed."<< std::endl;
	}
	catch (const AForm::GradeTooLowException &e){
		std::cout << this->getName() <<" cannot execute " << form.getName()  << " because: " << e.what() << "\nNeed higher Grade."<< std::endl;
	}
	catch (const std::logic_error &e){
		std::cout << "Caught LOGIC exception: " << e.what() << std::endl;
	}
	catch (const std::runtime_error &e){
		std::cout << "Caught RUN_TIME exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << "Caught UNKNOWN exception: " << e.what() << std::endl;
	}
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << endl;
	return (os);
}
