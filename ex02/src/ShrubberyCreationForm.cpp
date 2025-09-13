/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/09/13 18:48:12 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <stdexcept>

using std::string;
using std::endl;
using std::cout;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	cout << "ShrubberyCreationForm default constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, unsigned int gradeToSign, unsigned int gradeToEx) 
: AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToEx)
{
	cout << "ShrubberyCreationForm constructor called for " << _name << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const AForm& other) : AForm(other)
{
    cout << "ShrubberyCreationForm copy constructor called" << endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    cout << "ShrubberyCreationForm assignment operator called" << endl;
    ShrubberyCreationForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    cout << "ShrubberyCreationForm destructor called for " << _name << endl;
}
