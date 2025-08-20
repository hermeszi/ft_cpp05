/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/20 22:17:16 by myuen            ###   ########.fr       */
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
	
	struct GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Grade is max out at 1";
		}
	};
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Grade is lowest at 150!";
		}
	};

public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	~Bureaucrat();
	Bureaucrat	(const Bureaucrat& copy);
	Bureaucrat&	operator= (const Bureaucrat& other);

	std::string	getName() const;
	unsigned int			getGrade() const;

	void incrementGrade();
	void decrementGrade();
};

#endif
