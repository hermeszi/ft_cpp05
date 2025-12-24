/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/24 21:17:54 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

class Bureaucrat;
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm() {};
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	virtual void doExecute() const;
	
};


#endif
