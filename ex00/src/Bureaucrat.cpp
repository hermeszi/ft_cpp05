/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/23 22:22:05 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::string;
using std::endl;
using std::cout;

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
	cout << "Bureaucrat DEFAULT constructor called" << endl;
}

Bureaucrat::Bureaucrat(string name, unsigned int grade) : _name(name), _grade(gradeValid(grade))
{
	cout << "Bureaucrat constructor called for: " << _name  << " Grade: " << _grade << endl;
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
	cout << "Bureaucrat destructor: " << _name << endl;
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

unsigned int Bureaucrat::gradeValid(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << endl;
	return (os);
}
