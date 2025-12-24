/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/24 21:16:52 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>


#define SIGN 25
#define EXEC 5

using std::string;
using std::endl;
using std::cout;

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
    cout << "PresidentialPardonForm default constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", target, SIGN, EXEC)
{
    cout << this->getName() << " constructor called, target: " << this->getTarget() << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    cout << "PresidentialPardonForm copy constructor called" << endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    cout << "PresidentialPardonForm assignment operator called" << endl;
    AForm::operator=(other);
    return *this;
}

void PresidentialPardonForm::doExecute() const
{    
    cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << endl;
}

#undef SIGN
#undef EXEC
