/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/23 22:11:37 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#define SIGN 72
#define EXEC 45

using std::string;
using std::endl;
using std::cout;

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
	cout << "RobotomyRequestForm default constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm", target, SIGN, EXEC)
{
	cout << this->getName() << " constructor called, target: " << this->getTarget() << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    cout << "RobotomyRequestForm copy constructor called" << endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    cout << "RobotomyRequestForm assignment operator called" << endl;
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > EXEC)
        throw AForm::GradeTooLowException();
        
    cout << "Buzzz...Buzz..." << endl;
    if (rand() % 2 == 0)
        cout << this->getTarget() << " has been robotomized." << endl;
    else
        cout << this->getTarget() << " robotomy failed." << endl;
}

#undef EXEC
#undef SIGN

