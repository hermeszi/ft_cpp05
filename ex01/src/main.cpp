/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/08/22 21:28:15 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== BUREAUCRAT CLASS TESTING ===" << std::endl << std::endl;
	
	// Test 1: Valid Construction Cases
	std::cout << "--- Test 1: Valid Construction ---" << std::endl;
	try {
		// Test default constructor
		Bureaucrat defaultBureaucrat;
		std::cout << "Default bureaucrat: " << defaultBureaucrat << std::endl;
		
		// Test valid grade at boundaries (1 is highest, 150 is lowest)
		Bureaucrat highestGrade("Alice", 1);
		std::cout << "Highest grade: " << highestGrade << std::endl;
		
		Bureaucrat lowestGrade("Bob", 150);
		std::cout << "Lowest grade: " << lowestGrade << std::endl;
		
		// Test middle range grade
		Bureaucrat middleGrade("Charlie", 75);
		std::cout << "Middle grade: " << middleGrade << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Unexpected exception in valid construction: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 2: Invalid Construction - Grade Too High
	std::cout << "--- Test 2: Invalid Construction - Grade Too High ---" << std::endl;
	try {
		// Attempting to create bureaucrat with grade 0 (invalid - too high)
		Bureaucrat invalidHigh("David", 0);
		std::cout << "ERROR: Should have thrown exception for grade 0!" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Correctly caught GradeTooHighException: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught unexpected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 3: Invalid Construction - Grade Too Low
	std::cout << "--- Test 3: Invalid Construction - Grade Too Low ---" << std::endl;
	try {
		// Attempting to create bureaucrat with grade 151 (invalid - too low)
		Bureaucrat invalidLow("Eve", 151);
		std::cout << "ERROR: Should have thrown exception for grade 151!" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Correctly caught GradeTooLowException: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught unexpected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 4: Grade Increment (Promotion - Grade Goes Down Numerically)
	std::cout << "--- Test 4: Grade Increment (Promotion) ---" << std::endl;
	try {
		Bureaucrat promotionTest("Frank", 5);
		std::cout << "Before increment: " << promotionTest << std::endl;
		
		promotionTest.incrementGrade(); // Should go from 5 to 4
		std::cout << "After increment: " << promotionTest << std::endl;
		
		// Test incrementing at boundary - should work
		Bureaucrat boundaryTest("Grace", 2);
		boundaryTest.incrementGrade(); // Should go from 2 to 1
		std::cout << "Boundary increment (2->1): " << boundaryTest << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Unexpected exception during valid increment: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 5: Invalid Increment - Already at Highest Grade
	std::cout << "--- Test 5: Invalid Increment - Already at Highest ---" << std::endl;
	try {
		Bureaucrat maxGradeTest("Henry", 1);
		std::cout << "Starting at highest grade: " << maxGradeTest << std::endl;
		
		maxGradeTest.incrementGrade(); // Should throw exception
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Correctly caught exception when trying to increment grade 1: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught unexpected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 6: Grade Decrement (Demotion - Grade Goes Up Numerically)
	std::cout << "--- Test 6: Grade Decrement (Demotion) ---" << std::endl;
	try {
		Bureaucrat demotionTest("Iris", 10);
		std::cout << "Before decrement: " << demotionTest << std::endl;
		
		demotionTest.decrementGrade(); // Should go from 10 to 11
		std::cout << "After decrement: " << demotionTest << std::endl;
		
		// Test decrementing at boundary - should work
		Bureaucrat boundaryTest("Jack", 149);
		boundaryTest.decrementGrade(); // Should go from 149 to 150
		std::cout << "Boundary decrement (149->150): " << boundaryTest << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Unexpected exception during valid decrement: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 7: Invalid Decrement - Already at Lowest Grade
	std::cout << "--- Test 7: Invalid Decrement - Already at Lowest ---" << std::endl;
	try {
		Bureaucrat minGradeTest("Kate", 150);
		std::cout << "Starting at lowest grade: " << minGradeTest << std::endl;
		
		minGradeTest.decrementGrade(); // Should throw exception
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Correctly caught exception when trying to decrement grade 150: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught unexpected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 8: Copy Constructor
	std::cout << "--- Test 8: Copy Constructor ---" << std::endl;
	try {
		Bureaucrat original("Liam", 42);
		std::cout << "Original bureaucrat: " << original << std::endl;
		
		Bureaucrat copy(original);
		std::cout << "Copied bureaucrat: " << copy << std::endl;
		
		// Verify they're independent by modifying one
		copy.incrementGrade();
		std::cout << "After incrementing copy:" << std::endl;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Exception during copy constructor test: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 9: Assignment Operator
	std::cout << "--- Test 9: Assignment Operator ---" << std::endl;
	try {
		Bureaucrat source("Maya", 25);
		Bureaucrat target("Noah", 100);
		
		std::cout << "Before assignment:" << std::endl;
		std::cout << "Source: " << source << std::endl;
		std::cout << "Target: " << target << std::endl;
		
		target = source;
		std::cout << "After assignment:" << std::endl;
		std::cout << "Source: " << source << std::endl;
		std::cout << "Target: " << target << std::endl;
		
		// Note: If name is const, target should keep its original name
		// but adopt source's grade
		
	} catch (const std::exception& e) {
		std::cout << "Exception during assignment test: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// Test 10: Getter Methods
	std::cout << "--- Test 10: Getter Methods ---" << std::endl;
	try {
		Bureaucrat getterTest("Olivia", 88);
		
		std::cout << "Using getters separately:" << std::endl;
		std::cout << "Name: " << getterTest.getName() << std::endl;
		std::cout << "Grade: " << getterTest.getGrade() << std::endl;
		std::cout << "Using insertion operator: " << getterTest << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Exception during getter test: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
	
	return 0;
}
