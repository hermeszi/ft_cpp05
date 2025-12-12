/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/12 21:42:48 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>

#define SIGN 145
#define EXEC 137
#define TREE_CMD "find >>"
//| sed 's|[^/]*/|- |g' >>"


using std::string;
using std::endl;
using std::cout;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	cout << "ShrubberyCreationForm default constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("ShrubberyCreationForm", target, SIGN, EXEC)
{
	cout << this->getName() << " constructor called, target: " << this->getTarget() << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    cout << "ShrubberyCreationForm copy constructor called" << endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    cout << "ShrubberyCreationForm assignment operator called" << endl;
    AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream fout;  // Output stream
    
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > EXEC)
        throw AForm::GradeTooLowException();
        
    fout.open((getTarget() + "_shrubbery").c_str());
    if (!fout)
        throw std::runtime_error("output file failed");
    

    fout <<"           ,@@@@@@@,\n";
    fout <<"   ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    fout <<",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    fout <<",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    fout <<"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    fout <<"%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    fout <<"`&%\\ ` /%&'    |.|        \\ '|8'\n";
    fout <<"    |o|        | |         | |\n";
    fout <<"    |.|        | |         | |\n";
    fout <<" \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n\n";
    
    std::string cmd = TREE_CMD;
    std::string fileName = this->getTarget() + "_shrubbery";
    cmd += fileName;
    std::system(cmd.c_str());
    fout.close();
}

#undef EXEC
#undef SIGN
#undef TREE_CMD
