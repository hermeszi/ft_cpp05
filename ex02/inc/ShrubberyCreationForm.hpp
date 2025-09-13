/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/09/13 18:48:08 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

class Bureaucrat;
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name, unsigned int gradeToSign, unsigned int gradeToEx);
	virtual ~ShrubberyCreationForm() {};
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
};

std::ostream& operator<< (std::ostream& os, const ShrubberyCreationForm& f);

#endif
