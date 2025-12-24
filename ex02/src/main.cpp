/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12                                    #+#    #+#       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void header(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

static void showFile(const std::string& path)
{
    std::ifstream in(path.c_str());
    if (!in)
    {
        std::cout << "File check: cannot open '" << path << "' (not created?)" << std::endl;
        return;
    }

    std::cout << "File check: '" << path << "' contents (first 20 lines):" << std::endl;;
    std::string line;
    int count = 0;
    while (std::getline(in, line) && count++ < 20)
        std::cout << line << std::endl;
    if (count >= 20)
        std::cout << "...(truncated)\n" << std::endl;
}

// static void testShrubberyCreationForm()
// {
//     header("SHRUBBERY CREATION FORM TESTS");
    
//     header("Test 1: Execute BEFORE signing (should fail)");
//     try
//     {
//         ShrubberyCreationForm f("home");
//         Bureaucrat exec("ExecGuy", 1);

//         std::cout << f << std::endl;

//         try { f.execute(exec); }
//         catch (const AForm::FormNotSignedException& e) 
//         { 
//             std::cout << "Caught execute exception: " << e.what() << std::endl; 
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 2: Sign with LOW grade (should fail)");
//     try
//     {
//         ShrubberyCreationForm f("garden");
//         Bureaucrat low("LowGuy", 150);

//         low.signForm(f);
//         std::cout << f << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 3: Sign OK, execute with LOW grade (should fail)");
//     try
//     {
//         ShrubberyCreationForm f("fail");
//         Bureaucrat signer("Signer", 1);
//         Bureaucrat lowExec("LowExec", 150);

//         signer.signForm(f);
//         std::cout << f << std::endl;

//         try { f.execute(lowExec); }
//         catch (const std::exception& e) 
//         { 
//             std::cout << "Caught execute exception: " << e.what() << std::endl; 
//         }

//         showFile("fail_shrubbery");
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 4: Sign OK, execute OK (should create file)");
//     try
//     {
//         ShrubberyCreationForm f("42");
//         Bureaucrat signer("Signer", 1);
//         Bureaucrat exec("Exec", 1);

//         signer.signForm(f);
//         std::cout << f << std::endl;

//         try { f.execute(exec); }
//         catch (const std::exception& e) 
//         { 
//             std::cout << "Execute exception: " << e.what() << std::endl;; 
//         }

//         showFile("42_shrubbery");
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }
// }

// static void testRobotomyRequestForm()
// {
//     header("ROBOTOMY REQUEST FORM TESTS");
    
//     header("Test 1: Execute BEFORE signing (should fail)");
//     try
//     {
//         RobotomyRequestForm f("Bender");
//         Bureaucrat exec("ExecGuy", 1);

//         std::cout << f << std::endl;

//         try { f.execute(exec); }
//         catch (const AForm::FormNotSignedException& e) 
//         { 
//             std::cout << "Caught execute exception: " << e.what() << std::endl; 
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 2: Sign with LOW grade (should fail)");
//     try
//     {
//         RobotomyRequestForm f("Marvin");
//         Bureaucrat low("LowGuy", 150);

//         low.signForm(f);
//         std::cout << f << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 3: Sign OK, execute with LOW grade (should fail)");
//     try
//     {
//         RobotomyRequestForm f("R2D2");
//         Bureaucrat signer("Signer", 1);
//         Bureaucrat lowExec("LowExec", 150);

//         signer.signForm(f);
//         std::cout << f << std::endl;

//         try { f.execute(lowExec); }
//         catch (const std::exception& e) 
//         { 
//             std::cout << "Caught execute exception: " << e.what() << std::endl; 
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 4: Sign OK, execute OK (50% success rate)");
//     try
//     {
//         RobotomyRequestForm f("C3PO");
//         Bureaucrat signer("Signer", 1);
//         Bureaucrat exec("Exec", 1);

//         signer.signForm(f);
//         std::cout << f << std::endl;

//         try { f.execute(exec); }
//         catch (const std::exception& e) 
//         { 
//             std::cout << "Execute exception: " << e.what() << std::endl; 
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 5: Multiple executions (test randomness)");
//     try
//     {
//         RobotomyRequestForm f("Wall-E");
//         Bureaucrat signer("Signer", 1);
//         Bureaucrat exec("Exec", 1);

//         signer.signForm(f);
//         std::cout << f << std::endl;

//         std::cout << "Executing 5 times to test randomness:" << std::endl;
//         for (int i = 0; i < 5; i++)
//         {
//             std::cout << "Attempt " << (i + 1) << ": ";
//             try { f.execute(exec); }
//             catch (const std::exception& e) 
//             { 
//                 std::cout << "Execute exception: " << e.what() << std::endl; 
//             }
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }
// }

// static void testPresidentialPardonForm()
// {
//     header("Presidential Pardon Form TESTS");
    
//     header("Test 1: Execute BEFORE signing (should fail)");
//     try
//     {
//         PresidentialPardonForm f("Bender");
//         Bureaucrat exec("ExecGuy", 1);

//         std::cout << f << std::endl;

//         try { f.execute(exec); }
//         catch (const AForm::FormNotSignedException& e) 
//         { 
//             std::cout << "Caught execute exception: " << e.what() << std::endl; 
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 2: Sign with LOW grade (should fail)");
//     try
//     {
//         PresidentialPardonForm f("Marvin");
//         Bureaucrat low("LowGuy", 150);

//         low.signForm(f);
//         std::cout << f << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 3: Sign OK, execute with LOW grade (should fail)");
//     try
//     {
//         PresidentialPardonForm f("R2D2");
//         Bureaucrat signer("Signer", 1);
//         Bureaucrat lowExec("LowExec", 150);

//         signer.signForm(f);
//         std::cout << f << std::endl;

//         try { f.execute(lowExec); }
//         catch (const std::exception& e) 
//         { 
//             std::cout << "Caught execute exception: " << e.what() << std::endl; 
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     header("Test 4: Sign OK, execute OK - should be successful");
//     try
//     {
//         PresidentialPardonForm f("Zarniwoop");
//         Bureaucrat signer("Signer", 1);
//         Bureaucrat exec("Exec", 1);

//         signer.signForm(f);
//         std::cout << f << std::endl;

//         try { f.execute(exec); }
//         catch (const std::exception& e) 
//         { 
//             std::cout << "Execute exception: " << e.what() << std::endl; 
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }
// }

static void testExecuteFormWithForm(AForm& form, const std::string& formType)
{
    std::cout << "\n--- Testing " << formType << " ---\n";
    
    std::cout << "Test: Execute unsigned form\n";
    Bureaucrat exec1("HighGuy", 1);
    exec1.executeForm(form);
    
    std::cout << "\nTest: Sign then execute with low grade\n";
    Bureaucrat signer("Signer", 1);
    Bureaucrat lowExec("LowGuy", 150);
    signer.signForm(form);
    lowExec.executeForm(form);
    
    std::cout << "\nTest: Execute with sufficient grade\n";
    exec1.executeForm(form);
}

static void testBureaucratExecuteForm()
{
    header("BUREAUCRAT EXECUTEFORM() METHOD TESTS");
    
    try
    {
        ShrubberyCreationForm shrub("garden");
        testExecuteFormWithForm(shrub, "ShrubberyCreationForm");
        showFile("garden_shrubbery");
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << "\n";
    }
    
    try
    {
        RobotomyRequestForm robot("Bender");
        testExecuteFormWithForm(robot, "RobotomyRequestForm");
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << "\n";
    }
    
    try
    {
        PresidentialPardonForm pardon("Arthur");
        testExecuteFormWithForm(pardon, "PresidentialPardonForm");
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << "\n";
    }
}

int main()
{
    std::srand(std::time(0));
    
    // testShrubberyCreationForm();
    // testRobotomyRequestForm();
    // testPresidentialPardonForm();
    testBureaucratExecuteForm();

    return 0;
}
