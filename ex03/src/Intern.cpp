/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/25 20:56:57 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdexcept>

using std::string;
using std::endl;
using std::cout;

std::string Intern::formName[3] = { "shrubbery creation",
                                    "robotomy request",
                                    "presidential pardon" };

AForm* (*Intern::formCreator[3])(std::string) = {
    &Intern::createShrubbery,
    &Intern::createRobotomyRequest,
    &Intern::createPresidentialPardon
};                                   

Intern::Intern()
{
    cout << "Intern default constructor" << endl;    
}

Intern::Intern(const Intern & other)
{
    (void) other;
}

Intern::~Intern() {}

Intern & Intern::operator=(const Intern & other)
{
    if (this != &other)
    {
        (void) other;
    }
    
    return *this;
}

AForm* Intern::makeForm(string formName, string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (this->formName[i] == formName)
        {
            cout << "Intern creates " << this->formName[i] << endl;
            return (formCreator[i])(target);
        }
    }
    cout << "Intern can't find " << formName << endl;
    return NULL;
}

AForm* Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomyRequest(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}
