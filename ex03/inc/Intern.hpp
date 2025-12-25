/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/25 20:54:29 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
private:
    static std::string formName[3];
    static AForm*  (*formCreator[3])(std::string target);
    
    static AForm* createShrubbery(std::string target);
    static AForm* createRobotomyRequest(std::string target);
    static AForm* createPresidentialPardon(std::string target);
    
public:
    Intern();
    Intern(const Intern & other);
    
    ~Intern();
    
    Intern & operator=(const Intern & other);
    
    AForm* makeForm(std::string formName, std::string target);    
};

#endif
