/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/22 21:34:16 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
	std::string const	_name;
	unsigned int		_grade;

	static unsigned int gradeValid(unsigned int);
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	virtual ~Bureaucrat();
	Bureaucrat	(const Bureaucrat& copy);
	Bureaucrat&	operator= (const Bureaucrat& other);

	std::string		getName() const;
	unsigned int	getGrade() const;

	void incrementGrade();
	void decrementGrade();

	struct GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw() {return "INVALID: Grade is max out at 1!";}
	};	
	struct GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw() {return "INVALID: Grade is lowest at 150!";}
	};
};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat);

#endif
